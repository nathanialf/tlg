/* src/include/tlg_game_node.h: a node of the game's scene and its components
 * (game region; docs/TARGETS.md). Every name here is derived. A node's
 * components (+0x58, count +0x60) are scanned under the reader count at +0x30
 * (FUN_01331c10 takes it, an atomic decrement drops it); its children are
 * counted references (+0x40, count +0x48). Written with FUN_00503fb0
 * (func_00503fb0.cpp) and the components' type tests (leaf_009f54b0.cpp). */
#ifndef TLG_GAME_NODE_H
#define TLG_GAME_NODE_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_type.h"

struct Component00503fb0 { /* derived name */
    u8 unknown0[0x18];
    Type00503fb0 *type; /* +0x18 */
    u8 unknown20[0x34];
    Name name; /* +0x54 */
    u8 unknown58[0x30];
    int kind; /* +0x88 */
};

void FUN_01331c10(int *readers); /* derived name */

/* the released mark of a counted object: set when its last reference is
 * dropped on a thread that destroys it at once */
static const int RELEASED = 0xdeadc0de; /* derived name */

extern __thread bool D_16dc088; /* derived name: the thread destroys released objects itself */

class Node00503fb0; /* derived name */

void FUN_00c14bc0(Node00503fb0 *node); /* derived name: releases it later */

/* the value at `value` replaced by `replacement` when it is `expected`;
 * returns the value found (`lock cmpxchg; cmove eax, ecx` at every site: the
 * expected value is returned when the exchange was made) */
inline int compareAndSwap(int *value, int expected, int replacement) /* derived name */
{
    __atomic_compare_exchange_n(value, &expected, replacement, false, __ATOMIC_SEQ_CST,
                                __ATOMIC_SEQ_CST);
    return expected;
}

/* a counted reference to a node: the count at +0x8 of the node is left
 * alone once it holds the released mark */
template <class T> class Ref00503fb0 /* derived name */
{
  public:
    Ref00503fb0(const Ref00503fb0 &other) : object(other.object)
    {
        if (object && object->references != RELEASED)
            __sync_fetch_and_add(&object->references, 1);
    }

    ~Ref00503fb0()
    {
        release();
    }

    /* drops the reference and leaves this empty: the pointer is cleared
     * first (`mov qword [rdi], 0` before the count is read); the last
     * reference destroys the object at once on a thread whose flag is set,
     * else hands it to FUN_00c14bc0 */
    void release() /* derived name */
    {
        T *released = object;
        if (released) {
            object = 0;
            if (released->references != RELEASED &&
                __sync_fetch_and_sub(&released->references, 1) == 1) {
                if (D_16dc088) {
                    int count;
                    do
                        count = released->references;
                    while (compareAndSwap(&released->references, count, RELEASED) != count);
                    released->destroy();
                } else {
                    FUN_00c14bc0(released);
                }
            }
        }
    }

    T *get() const
    {
        return object;
    }

  private:
    T *object;
};

class Node00503fb0 /* derived name */
{
  public:
    virtual void unknown0();
    virtual void unknown1();
    virtual void destroy(); /* derived name; slot 2 */

    /* the first component from `next` on whose type is `type` or derives
     * from it; `next` is left after it */
    Component00503fb0 *findComponent(const Type00503fb0 *type, unsigned &next) /* derived name */
    {
        FUN_01331c10(&readers);
        Component00503fb0 *found = 0;
        for (int i = next; i < componentCount; ++i) {
            if (isKindOf(components[i]->type, type)) {
                found = components[i];
                next = i + 1;
                break;
            }
        }
        __sync_fetch_and_sub(&readers, 1);
        return found;
    }

    /* the first component whose type is `type` or derives from it */
    Component00503fb0 *findComponent(const Type00503fb0 *type) /* derived name */
    {
        unsigned next = 0;
        return findComponent(type, next);
    }

    int references; /* +0x8 */
    u8 unknownc[0x24];
    int readers;                         /* +0x30 */
    Node00503fb0 *parent;                /* +0x38 */
    Ref00503fb0<Node00503fb0> *children; /* +0x40 */
    unsigned childCount;                 /* +0x48 */
    u8 unknown4c[0xc];
    Component00503fb0 **components; /* +0x58 */
    unsigned componentCount;        /* +0x60 */
};

#endif

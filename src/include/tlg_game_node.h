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

/* the same for a pointer (`lock cmpxchg qword; cmove rax, rbx` at 0x45c487) */
template <class T>
inline T *compareAndSwap(T **value, T *expected, T *replacement) /* derived name */
{
    __atomic_compare_exchange_n(value, &expected, replacement, false, __ATOMIC_SEQ_CST,
                                __ATOMIC_SEQ_CST);
    return expected;
}

/* one more reference to a counted object; the count is left alone once it
 * holds the released mark */
template <class T> inline void addReference(T *object) /* derived name */
{
    if (object->references != RELEASED)
        __sync_fetch_and_add(&object->references, 1);
}

/* one reference less: the last one destroys the object at once on a thread
 * whose flag is set (the count swapped for the released mark first), else
 * hands it to FUN_00c14bc0 */
template <class T> inline void dropReference(T *object) /* derived name */
{
    if (object->references != RELEASED && __sync_fetch_and_sub(&object->references, 1) == 1) {
        if (D_16dc088) {
            int count;
            do
                count = object->references;
            while (compareAndSwap(&object->references, count, RELEASED) != count);
            object->destroy();
        } else {
            FUN_00c14bc0(object);
        }
    }
}

/* a counted reference to a node: the count at +0x8 of the node is left
 * alone once it holds the released mark */
template <class T> class Ref00503fb0 /* derived name */
{
  public:
    Ref00503fb0() : object(0) {}

    /* a reference to an object held by pointer (0xbe7e3f: the count raised
     * behind the null test) */
    explicit Ref00503fb0(T *object) : object(object)
    {
        if (object)
            addReference(object);
    }

    Ref00503fb0(const Ref00503fb0 &other) : object(other.object)
    {
        if (object)
            addReference(object);
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
            dropReference(released);
        }
    }

    T *get() const
    {
        return object;
    }

  private:
    T *object;
};

/* this thread's flag: set, the thread may use an object a name names
 * whatever the object's own flags say (1,158 sites read it) */
extern __thread bool D_16dc098; /* derived name */

/* whether this thread may use an object a name names: any thread when the
 * object's flag 4 at +0x16 is set, else a thread whose own flag is. T has
 * the field `flags16`. */
template <class T> inline bool isUsable(const T *object) /* derived name */
{
    return (object->flags16 & 4) || D_16dc098;
}

/* the object a name names (the record of its entry in the name table) when
 * this thread may use it and its type at +0x18 is `type` or derives from it,
 * else null; nothing is looked up for a null type. T has the fields
 * `flags16` and `type`. */
template <class T>
inline T *findNamed(const Name &name, const Type00503fb0 *type) /* derived name */
{
    T *found = 0;
    if (type) {
        T *object = static_cast<T *>(D_17ac870[name.index].record18);
        if (object && isUsable(object) && isKindOf(object->type, type))
            found = object;
    }
    return found;
}

/* a counted reference another thread may replace: the pointer is exchanged
 * by compare-and-swap, then the new object gains a reference and the old one
 * loses its own (FUN_0045c470 sets one from a pointer, FUN_013cfaa0 from
 * another reference, FUN_0079d400 empties one) */
template <class T> class AtomicRef0045c470 /* derived name */
{
  public:
    /* an object of a class over T goes in: the pointer is converted where
     * it is exchanged and compared (`cmp rsi, rbx` at 0x45c494, the
     * argument first, where an argument of T's own type compares second) */
    template <class U> void set(U *replacement) /* derived name */
    {
        T *old;
        do
            old = object;
        while (compareAndSwap(&object, old, static_cast<T *>(replacement)) != old);
        exchanged(old, replacement);
    }

    /* the other reference is read again at each attempt (`mov rcx, [rsi]`
     * inside the loop at 0x13cfab3) */
    AtomicRef0045c470 &operator=(const AtomicRef0045c470 &other)
    {
        T *old, *replacement;
        do {
            old = object;
            replacement = other.object;
        } while (compareAndSwap(&object, old, replacement) != old);
        exchanged(old, replacement);
        return *this;
    }

    void clear() /* derived name */
    {
        T *old;
        do
            old = object;
        while (compareAndSwap(&object, old, static_cast<T *>(0)) != old);
        if (old)
            dropReference(old);
    }

    /* the object as it is now (`cmp qword [rbx+0x38], 0` at 0x4ab651) */
    T *get() const
    {
        return object;
    }

  private:
    /* the counts after an exchange: nothing when the same object went in */
    static void exchanged(T *old, T *replacement) /* derived name */
    {
        if (replacement != old) {
            if (replacement)
                addReference(replacement);
            if (old)
                dropReference(old);
        }
    }

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
    u8 unknownc[0xa];
    u16 flags16;              /* +0x16: bit 2 lets any thread use the node (FUN_00618b00) */
    const Type00503fb0 *type; /* +0x18: the node's own type (FUN_00858390) */
    u8 flags20;               /* +0x20: bit 1 set when a child is taken out (FUN_00c57120) */
    u8 unknown21[0x3];
    int unknown24; /* +0x24: the index of the object's handler in a visitor's table (FUN_00589590) */
    u8 unknown28[0x8];
    int readers;                         /* +0x30 */
    Node00503fb0 *parent;                /* +0x38 */
    Ref00503fb0<Node00503fb0> *children; /* +0x40 */
    unsigned childCount;                 /* +0x48 */
    u8 unknown4c[0xc];
    Component00503fb0 **components; /* +0x58 */
    unsigned componentCount;        /* +0x60 */
};

#endif

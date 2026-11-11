/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_type.h"
#include <functional>

/* derived names: FUN_00503fb0 (0x1440 bytes) searches a tree of nodes with
 * one of two recursive lambdas, each held by a std::function on its frame
 * (rbp-0x60, built in place: the vtables 0x16aabe0 and 0x16aac30, the `lea`s
 * at 0x504257 and 0x504354) and capturing that std::function by reference.
 * When the int at +0x88 of its owner is 3 the first runs from the owner's
 * node (+0x28): it returns the node that has a component of the type
 * D_581b510 points to whose name is "barrelBox", searching the node's
 * children (an array of counted references at +0x40, their count at +0x48)
 * when it has none; its body (0x5065f0) is called directly at 0x504275 and
 * from the implementation's slot 2. Otherwise the second runs (inlined into
 * the creating function at 0x504370): it returns the node's first component
 * of the type D_57d9e90 points to if that component's int at +0x88 is 3,
 * else asks the node's parent (+0x38). A node's components (+0x58, count
 * +0x60) are scanned under the reader count at +0x30 (FUN_01331c10 takes it,
 * an atomic decrement drops it); a component's type is a chain of types
 * linked by their first field. The rest of the creating function is not
 * traced. */
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
        if (object && object->references != RELEASED &&
            __sync_fetch_and_sub(&object->references, 1) == 1) {
            if (D_16dc088) {
                int count;
                do
                    count = object->references;
                while (__sync_val_compare_and_swap(&object->references, count, RELEASED) != count);
                object->destroy();
            } else {
                FUN_00c14bc0(object);
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

extern Type00503fb0 *D_581b510; /* derived name */
extern Type00503fb0 *D_57d9e90; /* derived name */

struct Owner00503fb0 { /* derived name */
    u8 unknown0[0x28];
    Node00503fb0 *node; /* +0x28 */
    u8 unknown30[0x58];
    int kind; /* +0x88 */
};

void FUN_00503fb0_rest(Node00503fb0 *node,
                       Component00503fb0 *component); /* derived name: the rest, not traced */

// NONMATCHING: not written beyond the lambdas. The first lambda's body
// (0x5065f0) and the second's call slot (0x506830): the base keeps the
// component index an int sign-extended at each use (`movsxd`), where this
// build widens it (the parked IndVarSimplify class of 0xf501a0); the rest of
// each not compared beyond it. The first's call slot (0x5065e0) compiles
// equal but stays with its holder file: its tail call reaches the unclaimed
// body, which the layout cannot place. FUN_00503fb0_rest stands for the code that
// follows, which uses the node and the component apart.
void FUN_00503fb0(Owner00503fb0 *owner) /* derived name */
{
    Node00503fb0 *node = owner->node;
    Component00503fb0 *component = 0;
    if (owner->kind == 3) {
        std::function<Node00503fb0 *(Node00503fb0 *)> find =
            [&find](Node00503fb0 *node) -> Node00503fb0 * {
            unsigned next = 0;
            while (Component00503fb0 *component = node->findComponent(D_581b510, next)) {
                if (component->name == Name("barrelBox", false))
                    return node;
            }
            Node00503fb0 *found = 0;
            for (Ref00503fb0<Node00503fb0> *child = node->children;
                 child != node->children + node->childCount; ++child) {
                Ref00503fb0<Node00503fb0> held(*child);
                found = find(held.get());
                if (found)
                    break;
            }
            return found;
        };
        node = find(node);
    } else {
        std::function<Component00503fb0 *(Node00503fb0 *)> find =
            [&find](Node00503fb0 *node) -> Component00503fb0 * {
            unsigned next = 0;
            Component00503fb0 *component = node->findComponent(D_57d9e90, next);
            if (component && component->kind == 3)
                return component;
            if (Node00503fb0 *parent = node->parent)
                return find(parent);
            return 0;
        };
        component = find(node);
    }
    FUN_00503fb0_rest(node, component);
}

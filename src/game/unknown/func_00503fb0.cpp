/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
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

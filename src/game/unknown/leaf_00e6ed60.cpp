/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

extern Type00503fb0 *D_59391e0; /* derived name: a type of node that stands for another */
extern Type00503fb0 *D_5939080; /* derived name: the node's type */

void FUN_00c57220(Node00503fb0 *node); /* derived name; not traced */

/* derived names: the callback FUN_00e6b7f0 hands FUN_00cb8490 (lea at
 * 0xe6b8b7) with the address of a count of levels (an int it converted
 * from a script number): a node of the type D_59391e0 points to with no
 * levels left goes to FUN_00c5a160; one with levels left stands for the node
 * at its +0x28, one level spent. A node of the type D_5939080 points to then
 * goes up that many parents and the one reached goes to FUN_00c57220;
 * nothing is done when a parent runs out. Returns 1. */
// NONMATCHING: the first walk's not-found exit: the base goes on to the null test and reads the
// node's type again after loading D_5939080; here the unit's JumpThreading takes that edge past the
// null test (the node was dereferenced) and the type is reused (with kindOf for both walks the edge
// keeps its test, but each found edge out of a walk's loop tests the object again)
int FUN_00e6ed60(Node00503fb0 *node, const int *levels) /* derived name */
{
    int count = *levels;
    if (node->isKindOf(D_59391e0)) {
        if (count == 0) {
            FUN_00c5a160(node);
            return 1;
        }
        node = static_cast<Node00503fb0 *>(node->unknown28);
        --count;
    }
    if (node && node->isKindOf(D_5939080)) {
        for (int i = 0; i < count; ++i) {
            node = node->parent;
            if (!node)
                return 1;
        }
        FUN_00c57220(node);
    }
    return 1;
}

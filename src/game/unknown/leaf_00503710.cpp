/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: FUN_00503710 calls the given function with each component
 * of the type D_581b510 points to of a node and of every node below it
 * (children at +0x40, count +0x48, the count read again after each call),
 * the function's second argument 0. The components are scanned under the
 * node's reader count (FUN_01331c10, an atomic decrement drops it) and the
 * function is called with the count dropped. */
extern Type00503fb0 *D_581b510; /* derived name */

typedef void (*Visit00503710)(Component00503fb0 *component, int unknown); /* derived name */

// NONMATCHING: 96/98, 314 bytes as the base. The first drop folds its address (nextComponent's
// unlockRead) and the children's index is sign-extended at each use (childAt under an unsigned
// counter), as the base. Left: the visit pointer's move to r13 for the loop (`mov r13, rbx`, a copy
// the greedy allocator's split puts at the drop block's last split point) comes after the first
// `lock dec` where the base has it before (0x503782); the post-RA list scheduler moves it only
// above the test (round 587C)
void FUN_00503710(Object016b85e0 *node, Visit00503710 visit) /* derived name */
{
    unsigned next = 0;
    for (Component00503fb0 *component = node->nextComponent(D_581b510, next); component;
         component = node->nextComponent(D_581b510, next))
        visit(component, 0);
    for (unsigned i = 0; i < node->childCount; ++i)
        FUN_00503710(node->childAt(i), visit);
}

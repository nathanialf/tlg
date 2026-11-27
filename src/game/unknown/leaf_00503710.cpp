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

// The first drop folds its address (nextComponent's unlockRead) and the children's index is sign-extended
// at each use (childAt under an unsigned counter), as the base. The visit pointer's copy to r13 comes before
// the first `lock dec` (0x503782) by the post-RA rule for a locked decrement
// (tools/patches/llvm-3.7.1-lockdec-02-postra-locked-dec-last.patch, D97).
void FUN_00503710(Object016b85e0 *node, Visit00503710 visit) /* derived name */
{
    unsigned next = 0;
    for (Component00503fb0 *component = node->nextComponent(D_581b510, next); component;
         component = node->nextComponent(D_581b510, next))
        visit(component, 0);
    for (unsigned i = 0; i < node->childCount; ++i)
        FUN_00503710(node->childAt(i), visit);
}

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

// NONMATCHING: 78/98, 328 bytes against 314, the same under the rule of
// tools/patches/llvm-3.7.1-tailmerge-01-narrow-atomic-ends-tail.patch (the two drops are apart in
// both builds). Two residuals of known classes: the first find's drop through the call's kept
// address (`lock dec [r15]`) where the base forms it again (`lock dec [r14 + 0x30]` at 0x503785,
// FUN_01331c10's class in tlg_game_readlock.h), and the children's index widened to 64 bits
// (`inc rbx`) where the base sign-extends the int at each use (`movsxd rbx, ebx` at 0x503824, the
// parked IndVarSimplify class of func_00503fb0.cpp) (round 579D)
void FUN_00503710(Object016b85e0 *node, Visit00503710 visit) /* derived name */
{
    unsigned next = 0;
    for (Component00503fb0 *component = node->findComponent(D_581b510, next); component;
         component = node->findComponent(D_581b510, next))
        visit(component, 0);
    for (int i = 0; i < node->childCount; ++i)
        FUN_00503710(node->children[i].get(), visit);
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b8268.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the type the node must be of, and the type the class's
 * own objects have (its creator leaves the record at 0x5938310 for the root
 * class's constructor) */
extern const Type00503fb0 *D_5938308;
extern const Type00503fb0 *D_5938310;

/* derived names: slot 5 of the vtable at 0x16b8268 (a body of its own where the
 * base class's is FUN_000058a0, `mov eax, 1; ret`): 1 when the node is of the
 * type at 0x5938308 and holds no component of the class's own type, else 0. The
 * object itself is not read. */
// NONMATCHING: 13/52, 146 bytes against 156 (round 587C): FUN_009f6bc0's second search
// (leaf_009f6bc0.cpp): the base drops the count on each of three exits with the address folded
// (unlockRead's own, as here) and returns 0 or 1 by a branch on the answer, SimplifyCFG's
// FoldCondBranchOnPHI having copied the drop (D94); here the unit's first SimplifyCFG, run
// before hasComponent is inlined, has already turned the two returns into a value (`setne al;
// movzx; xor eax, 1`), so one drop is left. FUN_007b2d50, whose branch leads on to code, gets
// the copies from the same hasComponent.
int FUN_00c1efc0(Object016b8268 *, Object016b85e0 *node) /* derived name */
{
    if (!node->isKindOf(D_5938308) || node->hasComponent(D_5938310))
        return 0;
    return 1;
}

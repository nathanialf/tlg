/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: slot 5 of the vtables at 0x16b19f0 (FUN_009f6bc0) and at
 * 0x16b1a48 (FUN_009f8a90), one body: true when the node has a component of
 * neither the type the pointer at 0x5823928 holds nor the one at 0x5823930
 * (or of one derived from either), each searched under the node's reader
 * count. The object itself is not read; each is a free function here, as
 * the classes' other slots are (leaf_009f6ca0.cpp). */
class Object016b19f0;
class Object016b1a48;

extern const Type00503fb0 *D_5823928; /* derived name */
extern const Type00503fb0 *D_5823930; /* derived name */

// NONMATCHING: 38/74, 209 bytes against 223 (round 587C). The first search is the base's (one
// `lock dec` block with "none found" in al, its address folded: component()'s unlockRead, whose
// address the second search's drops then share, so SimplifyCFG cannot copy the first block). The
// second: the base drops the count on each of its three exits (0x9f6c73, 0x9f6c7e, 0x9f6c8b), the
// found pointer tested after its own and 0 or 1 returned by a branch, SimplifyCFG's
// FoldCondBranchOnPHI on hasComponent's answer (D94; FUN_007b2d50 gets them from this helper);
// here the unit's first SimplifyCFG, before the helper is inlined, makes the returns a value
// (`sete al; movzx eax, al`). Measured the same: `if (a || b) return 0; return 1;` and component()
// for the second; hasComponent with an early return in its loop gives 55/74 (the found exit apart,
// the empty array and the loop's end one drop), not the base's mechanism. The same in FUN_009f8a90
// and FUN_00b88680.
int FUN_009f6bc0(Object016b19f0 *, Object016b85e0 *node) /* derived name */
{
    return !node->component(D_5823928) && !node->hasComponent(D_5823930);
}

/* FUN_009f8a90: the same body */
int FUN_009f8a90(Object016b1a48 *, Object016b85e0 *node) /* derived name */
{
    return !node->component(D_5823928) && !node->hasComponent(D_5823930);
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: slot 5 of the vtable at 0x16b6dc8 (Object016b6dc8), 0x16b6e28 (Object016b6e28), 0x16b6e88 (Object016b6e88), 0x16b6ee8 (Object016b6ee8): true when the node has no
 * component of the type D_5835c40 points to (or of one derived from it); the
 * object itself is not read. FUN_009f54b0's copy (leaf_009f54b0.cpp). */
struct Object00b7f820; /* derived name */

extern Type00503fb0 *D_5835c40; /* derived name */

// NONMATCHING: 35 of 37: the result's `movzx eax, al` after the count's drop, where the base
// extends it before (`movzx eax, al; lock dec dword ptr [r14 + 0x30]`); the int made under the
// lock (componentLocked between lockRead and unlockRead) loads the type after the lock's call
// and still extends after the drop (round 569D)
int FUN_00b7f820(Object00b7f820 *, Object016b85e0 *node) /* derived name */
{
    return node->component(D_5835c40) == 0;
}

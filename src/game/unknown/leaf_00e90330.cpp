/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: slot 5 of the vtable at 0x16be190 (Object016be190): true when the node has no
 * component of the type D_5a8d750 points to (or of one derived from it); the
 * object itself is not read. FUN_009f54b0's copy (leaf_009f54b0.cpp). */
struct Object00e90330; /* derived name */

extern Type00503fb0 *D_5a8d750; /* derived name */

// The result is extended before the count's drop (`movzx eax, al; lock dec dword ptr [r14 + 0x30]`)
// by the post-RA rule for a locked decrement
// (tools/patches/llvm-3.7.1-lockdec-02-postra-locked-dec-last.patch, D97).
int FUN_00e90330(Object00e90330 *, Object016b85e0 *node) /* derived name */
{
    return node->component(D_5a8d750) == 0;
}

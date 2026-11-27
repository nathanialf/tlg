/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: a virtual slot of a component class (held at 0x16b19a8): true
 * when the node has no component of the type D_58237e8 points to (or of one
 * derived from it). The object itself is not read. Class and method unknown. */
struct Object009f54b0; /* derived name */

extern Type00503fb0 *D_58237e8; /* derived name */

// The result is extended before the count's drop (`movzx eax, al; lock dec dword ptr [r14 + 0x30]`)
// by the post-RA rule for a locked decrement
// (tools/patches/llvm-3.7.1-lockdec-02-postra-locked-dec-last.patch, D97).
int FUN_009f54b0(Object009f54b0 *, Object016b85e0 *node) /* derived name */
{
    return node->component(D_58237e8) == 0;
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: a virtual slot of a component class (held at 0x16b19a8): true
 * when the node has no component of the type D_58237e8 points to (or of one
 * derived from it). The object itself is not read. Class and method unknown. */
struct Object009f54b0; /* derived name */

extern Type00503fb0 *D_58237e8; /* derived name */

// NONMATCHING: with isKindOf defined out of line (tlg_game_type.h) the control flow is the base's
// (`mov al, 1` before the loop, `test rdi, rdi; sete al` in the found arm) and the result an int
// (`movzx eax, al`). Left: the base forms the count's address twice (`lea rdi, [r14 + 0x30]` for
// FUN_01331c10, `lock dec dword [r14 + 0x30]`) where the build keeps it in r14 (one push more):
// CodeGenPrepare does not sink an address into an atomic user (round 325C's class, region-wide)
int FUN_009f54b0(Object009f54b0 *, Object016b85e0 *node) /* derived name */
{
    return node->findComponent(D_58237e8) == 0;
}

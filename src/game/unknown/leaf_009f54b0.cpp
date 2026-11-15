/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: a virtual slot of a component class (held at 0x16b19a8): true
 * when the node has no component of the type D_58237e8 points to (or of one
 * derived from it). The object itself is not read. Class and method unknown. */
struct Object009f54b0; /* derived name */

extern Type00503fb0 *D_58237e8; /* derived name */

// NONMATCHING: the loop and its index are the base's now (an unsigned counter, the components'
// index an int). Left: the base forms the count's address twice (`lea rdi, [r14 + 0x30]` for
// FUN_01331c10, `lock dec dword [r14 + 0x30]`) where the build keeps it in r14 (the atomic
// decrement's address is one value with the call's argument and is in another block: a count
// in a struct of its own, its address formed from the struct's, is still one value); and the
// base tests the found component before the decrement (`test rdi, rdi; sete al` in the found
// arm, `mov al, 1` set before the loop), the build after it
bool FUN_009f54b0(Object009f54b0 *, Node00503fb0 *node) /* derived name */
{
    return node->findComponent(D_58237e8) == 0;
}

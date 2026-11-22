/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_jscomputecontext.h"

/* derived names: FUN_01302220 called with the context, its first argument
 * and its third (64-bit, `mov rdx, rcx`), the second unused, as a tail
 * call. The argument types and the return type are not traced. */
void FUN_01302220(JsComputeContext *self, void *first, void *third); /* derived name */

void JsComputeContext::slot16(void *first, void *, void *third)
{
    FUN_01302220(this, first, third);
}

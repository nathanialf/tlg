/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 14 of the vtable at 0x16bb0c0 (its pointer at 0x16bb140):
 * pushes a loop record of kind 1 with no jump at +0x14 */
void FUN_00dafab0(CodeGen016bb0c0 *self) /* derived name */
{
    Loop016bb0c0 *loop = self->functions.top->loops.push();
    loop->kind = 1;
    loop->unknown14 = -1;
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 66 of the vtable at 0x16bb0c0 (its pointer at 0x16bb2e0):
 * declares the argument as the local of the next index at +0x17b0,
 * then pushes an empty record on the stack at +0x1d68 */
void FUN_00dad260(CodeGen016bb0c0 *self, Name016bb0c0 *name) /* derived name */
{
    FUN_00daba60(self, name, self->functions.top->unknown17b0, -1, 0);
    ++self->functions.top->unknown17b0;
    Slot016bb0c0 *slot = self->functions.top->slots.push();
    slot->type = -1;
    slot->structure = 0;
    slot->unknown10 = 0;
}

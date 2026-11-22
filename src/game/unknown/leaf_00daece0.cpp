/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 37 of the vtable at 0x16bb0c0 (its pointer at 0x16bb1f8):
 * the generic for's hidden locals declared (Lua's forlist; the names
 * are facts), counted by the loop record from 1 */
void FUN_00daece0(CodeGen016bb0c0 *self) /* derived name */
{
    Loop016bb0c0 *loop = self->functions.top->loops.top;
    loop->hidden = 1;
    declareLocal(self, "(for generator)", 15, 0, -1);
    declareLocal(self, "(for state)", 11, loop->hidden++, -1);
    declareLocal(self, "(for control)", 13, loop->hidden++, -1);
}

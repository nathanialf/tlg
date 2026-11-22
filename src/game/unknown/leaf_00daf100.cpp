/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 25 of the vtable at 0x16bb0c0 (its pointer at 0x16bb198):
 * the numeric for (Lua's fornum): a loop record pushed (kind 0, no
 * jump at +0x14, the free register's low word, the line given at +0x4,
 * 1 at +0x10), then its three hidden locals declared as numbers (type 3;
 * the names are facts) */
void FUN_00daf100(CodeGen016bb0c0 *self, int line) /* derived name */
{
    Loop016bb0c0 *loop = self->functions.top->loops.push();
    loop->kind = 0;
    loop->unknown14 = -1;
    loop->unknownc = self->functions.top->freeRegister;
    loop->unknown4 = line;
    loop->unknown10 = 1;
    declareLocal(self, "(for index)", 11, 0, 3);
    declareLocal(self, "(for limit)", 11, 1, 3);
    declareLocal(self, "(for step)", 10, 2, 3);
}

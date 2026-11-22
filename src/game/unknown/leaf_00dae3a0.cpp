/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 42 of the vtable at 0x16bb0c0 (its pointer at 0x16bb220):
 * a repeat loop's start (Lua's repeatstat before the block): a loop record
 * of kind 2 pushed with no exits, the current pc marked as a jump's target
 * and kept as the loop's start, then the loop's block (breakable) and the
 * scope's block begun (FUN_00dae680 ends them) */
void FUN_00dae3a0(CodeGen016bb0c0 *self) /* derived name */
{
    Loop016bb0c0 *loop = self->functions.top->loops.push();
    loop->kind = 2;
    loop->unknown14 = -1;
    self->functions.top->lastTarget = self->functions.top->code.count;
    self->functions.top->loops.top->unknown4 = self->functions.top->code.count;
    enterBlock(self, 1);
    enterBlock(self, 0);
}

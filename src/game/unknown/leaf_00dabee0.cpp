/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 54 of the vtable at 0x16bb0c0 (its pointer at 0x16bb280):
 * the end of a parameter list (Lua's parlist): the parameters made
 * active, their count less an "arg" parameter, their registers taken */
void FUN_00dabee0(CodeGen016bb0c0 *self) /* derived name */
{
    activateLocals(self, self->functions.top->parameterCount);
    self->functions.top->parameterCount =
        self->functions.top->activeCount - (self->functions.top->vararg & 1);
    reserveRegisters(self, self->functions.top->activeCount);
}

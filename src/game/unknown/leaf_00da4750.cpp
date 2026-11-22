/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 3 of the vtable at 0x16bb0c0 (its pointer at 0x16bb0e8):
 * closes the function compiled on top (as Lua's close_func): its end coded
 * (FUN_00da47f0), what it left at +0x8 kept at +0x7de8, the table it pushed
 * popped from the script state, then the function popped from the stack
 * and its state destroyed */
void FUN_00da4750(CodeGen016bb0c0 *self) /* derived name */
{
    FUN_00da47f0(self);
    self->unknown7de8 = self->functions.top->unknown8;
    hksi_lua_pop(self->functions.top->state, 1);
    ScriptFunction016bb0c0 *fs = self->functions.top;
    FUN_013bdae0(&self->functions);
    FUN_00da3790(fs);
}

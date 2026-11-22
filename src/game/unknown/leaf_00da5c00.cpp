/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 133 of the vtable at 0x16bb0c0 (its pointer at 0x16bb4f8):
 * a call as a statement uses no results: C of the instruction of the
 * expression on top set to 1, the instruction found twice as Lua's
 * SETARG_C(getcode(fs, e), 1) expands it */
void FUN_00da5c00(CodeGen016bb0c0 *self) /* derived name */
{
    ScriptFunction016bb0c0 *fs = self->function;
    SCRIPT_SET_C(SCRIPT_CODE(fs, fs->expressions.top), 1);
}

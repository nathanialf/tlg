/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>
#include "tlg_game_scriptcode.h"

/* derived names: slot 40 of the vtable at 0x16bb0c0 (its pointer at 0x16bb210):
 * the loop's word at +0x4 set from slot 4 of the reporter, then an
 * expression and an empty record on the stack at +0x17c0 pushed */
void FUN_00daee10(CodeGen016bb0c0 *self) /* derived name */
{
    self->functions.top->loops.top->unknown4 = self->lexer->slot4();
    self->functions.top->expressions.push();
    new (self->functions.top->pending.push()) Pending016bb0c0(self->state);
}

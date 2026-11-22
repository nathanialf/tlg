/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>
#include "tlg_game_scriptcode.h"

/* derived names: slot 127 of the vtable at 0x16bb0c0 (its pointer at 0x16bb4c8):
 * pushes an empty record on the stack at +0x17c0 */
void FUN_00da6eb0(CodeGen016bb0c0 *self) /* derived name */
{
    new (self->function->pending.push()) Pending016bb0c0(self->state);
}

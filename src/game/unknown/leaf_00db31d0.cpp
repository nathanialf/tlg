/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 145 of the vtable at 0x16bb0c0 (its pointer at 0x16bb558):
 * with structures enabled, the structure of the name given looked up
 * in the state's table of structures and kept at +0x9310, an error when
 * there is none (the message is a fact) */
// NONMATCHING: the base carries the value's type and value as two pointers out of the lookup
// (`lea r8, [node+0x10]; add node, 0x18` against the nil value's two addresses), the build one
// pointer to the value and two loads after it
void FUN_00db31d0(CodeGen016bb0c0 *self, ScriptString016bb0c0 *name) /* derived name */
{
    if (!self->structures)
        return;
    const HksValue016bb0c0 *value = findString(self->state->allocator->structures, name);
    Structure016bb0c0 *structure =
        (value->type & 0xf) == 7 ? &static_cast<StructureObject016bb0c0 *>(value->value)->structure
                                 : 0;
    if (!structure) {
        char message[0x400];
        FUN_00d95b60(message, sizeof(message), "Attempt to reference an undefined structure '%s'.",
                     name->chars);
        self->lexer->error(message);
    }
    self->structure = structure;
}

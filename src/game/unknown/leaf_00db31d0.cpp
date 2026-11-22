/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 145 of the vtable at 0x16bb0c0 (its pointer at 0x16bb558):
 * with structures enabled, the structure of the name given looked up
 * in the state's table of structures and kept at +0x9310, an error when
 * there is none (the message is a fact) */
// NONMATCHING: the base tests the structure's pointer after the select (`cmove rbx, rax; test rbx,
// rbx`); the build branches on the type's compare (the field's address taken as never null)
void FUN_00db31d0(CodeGen016bb0c0 *self, ScriptString016bb0c0 *name) /* derived name */
{
    if (!self->structures)
        return;
    HksValue016bb0c0 value;
    findString(self->state->allocator->structures, name, value);
    Structure016bb0c0 *structure =
        (value.type & 0xf) == 7 ? &static_cast<StructureObject016bb0c0 *>(value.value)->structure
                                : 0;
    if (!structure) {
        char message[0x400];
        FUN_00d95b60(message, sizeof(message), "Attempt to reference an undefined structure '%s'.",
                     name->chars);
        self->lexer->error(message);
    }
    self->structure = structure;
}

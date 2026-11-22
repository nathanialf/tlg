/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 94 of the vtable at 0x16bb0c0 (its pointer at 0x16bb3c0):
 * with structures enabled, an error when the table constructor
 * builds an instance of a structure whose instances take no other keys (the message is
 * a fact); then an expression is pushed */
void FUN_00daa5b0(CodeGen016bb0c0 *self) /* derived name */
{
    Structure016bb0c0 *structure = self->constructors.top->structure;
    if (self->structures && structure && !structure->open) {
        char message[0x400];
        FUN_00d95b60(message, sizeof(message),
                     "Attempt to assign to number indexes on instances of structure '%s' is not "
                     "allowed.",
                     structure->name->chars);
        self->lexer->error(message);
    }
    self->function->expressions.push();
}

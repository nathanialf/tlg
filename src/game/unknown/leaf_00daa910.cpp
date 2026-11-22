/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: slot 98 of the vtable at 0x16bb0c0 (its pointer at 0x16bb3e0):
 * a keyed item of the table constructor (Lua's recfield): the count of
 * hash items checked against its limit; with structures enabled, an error
 * when the structure the constructor builds declares no slot of the name
 * given and its instances take no other keys (the message is a fact); the
 * expression on top set to the name's string constant */
void FUN_00daa910(CodeGen016bb0c0 *self, ScriptString016bb0c0 *name) /* derived name */
{
    checkLimit(self, self->constructors.top->hashItems, 0x7fffffff,
               "hash items in a table constructor.");
    Structure016bb0c0 *structure = self->constructors.top->structure;
    if (self->structures && structure && !hasSlot(structure, name) && !structure->open) {
        char message[0x400];
        FUN_00d95b60(message, sizeof(message),
                     "Attempt to assign slot '%s' on instances of '%s is not allowed.", name->chars,
                     structure->name->chars);
        self->lexer->error(message);
    }
    Expression016bb0c0 *e = self->functions.top->expressions.top;
    initExpression(e, 4, stringConstant(self, name), 4);
}

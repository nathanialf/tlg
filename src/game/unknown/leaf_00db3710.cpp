/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: the names of the script VM's types from type -2 ("object",
 * "no value", "nil", ... "struct") */
extern const char *const D_16bc020[];

/* derived names: slot 136 of the vtable at 0x16bb0c0 (its pointer at
 * 0x16bb510): the numeric for's variable declared with a type (the message
 * is a fact): the type name resolved by FUN_00db3300, an error unless it
 * is none, nil or a number, then the local declared at index 3 */
void FUN_00db3710(CodeGen016bb0c0 *self, Name016bb0c0 *name,
                  ScriptString016bb0c0 *typeName) /* derived name */
{
    int type = -1;
    Structure016bb0c0 *structure;
    FUN_00db3300(self, typeName, &type, &structure);
    if (type != -1 && type != 0 && type != 3) {
        char message[0x400];
        FUN_00d95b60(message, sizeof(message),
                     "Only 'number' is allowed as a type for numeric FOR iterator. Got '%s'",
                     D_16bc020[type + 2]);
        self->lexer->error(message);
    }
    FUN_00daba60(self, name, 3, type, structure);
}

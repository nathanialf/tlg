/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"

/* derived names: resolves a type declaration's name (the messages are
 * facts): FUN_00db26b0 gives the built-in type of the name (-1 none, -2
 * "object", 12 "struct"); a name that is not built in is looked up in the
 * state's table of structures, a structure's object giving type 12 and the
 * structure; "object" gives no type (-1), "struct" itself is an error;
 * called by 0xdb3520, 0xdb3710 and two more */
// NONMATCHING: register assignment: the base keeps the name in r13 and reloads the stack guard's
// address at the end; the build keeps the guard's address in a register
void FUN_00db3300(CodeGen016bb0c0 *self, ScriptString016bb0c0 *name, int *type,
                  Structure016bb0c0 **structure) /* derived name */
{
    int builtIn = FUN_00db26b0(name);
    *structure = 0;
    if (builtIn == -1) {
        HksValue016bb0c0 value;
        findString(self->state->allocator->structures, name, value);
        if ((value.type & 0xf) == 7) {
            *type = 12;
            *structure = &static_cast<StructureObject016bb0c0 *>(value.value)->structure;
        } else {
            char message[0x400];
            FUN_00d95b60(message, sizeof(message),
                         "Type declaration '%s' does not match any built-in type or structure.",
                         name->chars);
            self->lexer->error(message);
        }
    } else if (builtIn == -2) {
        *type = -1;
    } else if (builtIn == 12) {
        self->lexer->error("Type declaration 'struct' is not allowed.");
    } else {
        *type = builtIn;
    }
}

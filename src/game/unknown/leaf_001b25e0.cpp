/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_hks.h"
#include "tlg_libc.h"

/* derived names: the script C function FUN_001bd010 registers (lea at
 * 0x1db382) under the script name "CombineSceneRoot": with at least one
 * argument, the object the first argument's string names (interned as a
 * copy: the last argument of FUN_013baad0 0), of the type D_5948b00
 * points to (usable by this thread), is handed to FUN_0081e8d0; returns 0
 * (no results). A null or empty string names nothing. The C function's own
 * name is unknown; the class is not traced. */
struct Object001b25e0 : Object016b9108 /* derived name */
{};

extern const Type00503fb0 *D_5948b00; /* derived name: the object's type */

void FUN_0081e8d0(Object001b25e0 *object); /* derived name */

int FUN_001b25e0(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count > 0) {
        const char *string = 0;
        if (state->base < state->top)
            string = FUN_00db6b20(state, state->base, 0);
        Name name;
        if (string && *string)
            name.index = FUN_013baad0(string, FUN_013bad90(string), strlen(string), false);
        Object001b25e0 *object = findNamed<Object001b25e0>(name, D_5948b00);
        if (object)
            FUN_0081e8d0(object);
    }
    return 0;
}

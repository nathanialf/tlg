/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: Lua's lua_setfenv by its arguments: the object's
 * environment set to the table on the stack's top, whether it took one
 * (FUN_00db7c80, its body not written) */
int FUN_00db7c80(lua_State *state, const HksObject *object);

/* derived name: the debug library's "setfenv" (its entry in the table at
 * 0x16bc910): with two arguments or more, the environment of the value
 * under the top set to the table on the top, which is popped; one result
 * when it took, none otherwise */
/* derived name: Lua's lua_setfenv(state, -2): the environment of the value
 * under the stack's top set to the top, which is popped; whether it took */
inline int setEnvironmentBelow(lua_State *state)
{
    const HksObject *object = state->top - 2;
    int result = 0;
    if (object >= state->base)
        result = FUN_00db7c80(state, object);
    --state->top;
    return result;
}

// NONMATCHING: register assignment (the base holds the top in rdx and the base in rax) and the result as `setne`
int FUN_00deb490(lua_State *state)
{
    if (argumentCount(state) >= 2) {
        const HksObject *table = state->top - 1;
        int type = -1;
        if (table >= state->base) {
            type = table->type & 0xf;
            if (type == 9 || type == 10)
                type = 6;
        }
        if (type != 5)
            FUN_00dd38c0(state, -1, "table");
        if (setEnvironmentBelow(state))
            return 1;
    }
    return 0;
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"
#include "tlg_hks_string.h"

/* derived name: the coroutine library's "status" (its entry in the table at
 * 0x16bc850): the first argument's state as a string, "running" for the
 * calling thread itself, nil for a state it does not name */
// NONMATCHING: the thread's slot is made null past the top (`cmovae`) and the base tests no null after it; here a
// `test rcx, rcx` remains (the slot not known non-null)
int FUN_00decef0(lua_State *state)
{
    hksi_luaL_checktype(state, 1, 8, "thread");
    lua_State *thread = toThread(state, 1);
    const char *status;
    if (thread == state) {
        status = "running";
    } else {
        switch (thread->status) {
        case 1:
            status = argumentCount(thread) != 0 ? "suspended" : "dead";
            break;
        case 2:
            status = "normal";
            break;
        case 3:
            status = "suspended";
            break;
        case 4:
            status = "dead";
            break;
        default:
            pushNil(state);
            return 1;
        }
    }
    pushString(state, status);
    return 1;
}

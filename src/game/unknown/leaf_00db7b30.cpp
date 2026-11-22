/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: Lua's getfenv of a value: the environment's table of a
 * userdata (7), a thread (8, its globals) or a function (9, 10) written to
 * `environment`, nil for any other value or none; the call timed */
void FUN_00db7b30(lua_State *state, const HksObject *object, HksObject *environment)
{
    HksApiTimer timer(state);
    void *table;
    switch (object->type & 0xf) {
    case 7:
        table = static_cast<HksUserdata *>(object->value.pointer)->environment;
        break;
    case 8:
        table = static_cast<lua_State *>(object->value.pointer)->globals;
        break;
    case 9:
        table = static_cast<HksClosure *>(object->value.pointer)->environment;
        break;
    case 10:
        table = static_cast<HksCClosure *>(object->value.pointer)->environment;
        break;
    default:
        table = 0;
        break;
    }
    if (table) {
        environment->value.pointer = table;
        environment->type = 5;
    } else {
        environment->type = 0;
    }
}

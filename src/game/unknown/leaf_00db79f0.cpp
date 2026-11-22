/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: Lua's lua_rawequal by its operands: two values of one
 * type, both nil, equal numbers, equal booleans or the same object; the
 * call timed */
int FUN_00db79f0(lua_State *state, const HksObject *a, const HksObject *b)
{
    HksApiTimer timer(state);
    const int type = a->type & 0xf;
    if (type != (b->type & 0xf))
        return 0;
    if (type == 0)
        return 1;
    if (type == 3)
        return a->value.number == b->value.number;
    if (type == 1)
        return a->value.boolean == b->value.boolean;
    return a->value.pointer == b->value.pointer;
}

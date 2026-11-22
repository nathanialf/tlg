/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"
#include "tlg_hks_string.h"

/* derived names: an argument's integer (FUN_00dbf960, leaf_00dbf3f0.cpp's)
 * and an optional one, the default when it is absent (FUN_00dc0440); their
 * bodies not written */
int FUN_00dbf960(lua_State *s, int argument);
int FUN_00dc0440(lua_State *s, int argument, int def);

/* derived name: Lua's posrelat: a position counted from the end made one
 * from the start */
static inline int posrelat(int pos, size_t len)
{
    if (pos < 0)
        pos += (int)len + 1;
    return pos;
}

/* derived name: the string library's "sub" (its entry in the table at
 * 0x16bcfe0): the characters of the first argument from the second
 * position to the third (the string's end by default) */
// NONMATCHING: register assignment only: the base takes the start's sign in edi and the length plus one in esi
int FUN_00de14d0(lua_State *state)
{
    size_t l = 0;
    const char *s = hksi_luaL_checklstring(state, 1, &l);
    int start = FUN_00dbf960(state, 2);
    int end = FUN_00dc0440(state, 3, l);
    setTop(state, 1);
    start = posrelat(start, l);
    end = posrelat(end, l);
    start = start > 0 ? start : 1;
    end = end < (int)l + 1 ? end : (int)l;
    if (end >= start)
        FUN_013aacc0(state, s + start - 1, end + 1 - start);
    else
        FUN_013aacc0(state, "", 0);
    return 1;
}

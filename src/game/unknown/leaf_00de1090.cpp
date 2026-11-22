/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived name: an argument's integer (FUN_00dbf960, its body not
 * written; leaf_00dbf3f0.cpp's) */
int FUN_00dbf960(lua_State *s, int argument);

/* derived name: the string library's "char" (its entry in the table at
 * 0x16bcfb0): the string of the arguments' character codes */
// NONMATCHING: the buffer's end: the base keeps the buffer's address in r15 for the store of p and adds 0x200
// to it before the loop; here the end is its own frame address (`lea r15, [rbp-0x30]`)
int FUN_00de1090(lua_State *state)
{
    const int count = argumentCount(state);
    luaL_Buffer b;
    hksi_luaL_buffinit(state, &b);
    for (int i = 1; i <= count; i++)
        luaL_addchar(&b, FUN_00dbf960(state, i));
    luaL_pushresult(&b);
    return 1;
}

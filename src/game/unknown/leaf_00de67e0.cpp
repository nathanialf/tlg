/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"
#include "tlg_libc.h"

/* derived name: an argument's integer (FUN_00dbf960, its body not
 * written; leaf_00dbf3f0.cpp's) */
int FUN_00dbf960(lua_State *s, int argument);

/* derived name: the os library's "difftime" (its entry in the table at
 * 0x16bcd60): the seconds from the second time to the first, the stack
 * emptied before the result is pushed */
int FUN_00de67e0(lua_State *state)
{
    const time_t end = FUN_00dbf960(state, 1);
    const time_t start = FUN_00dbf960(state, 2);
    setTop(state, 0);
    pushNumber(state, difftime(end, start));
    return 1;
}

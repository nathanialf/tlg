/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object05945a38.h"
#include "tlg_hks.h"

/* derived names: the script C function "DisconnectAll" (the name
 * FUN_00e6e060's registration gives it, lea at 0xe6e1ac): with an argument,
 * the type its name names (D_5945a38's table) has each of its objects
 * handed to FUN_00e6ed60 by FUN_00cb8490 with the second argument's number
 * as an int, the levels (0 without one). Returns 0 (no results). */
int FUN_00e6ed60(Object016b9108 *object, const int *levels); /* derived name */
void FUN_00cb8490(Type00503fb0 *type, int (*visit)(Object016b9108 *object, const int *levels),
                  const int *levels); /* derived name */

int FUN_00e6b7f0(lua_State *state) /* derived name */
{
    int count = argumentCount(state);
    if (count > 0) {
        int levels;
        Name name = nameArgument(state, 1);
        levels = count >= 2 ? (int)toNumber(state, 2) : 0;
        if (Type00503fb0 *type = D_5945a38->type(name))
            FUN_00cb8490(type, FUN_00e6ed60, &levels);
    }
    return 0;
}

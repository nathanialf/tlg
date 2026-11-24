/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object05945a38.h"
#include "tlg_hks.h"

/* derived names: a script C function (its address is not stored where a
 * table was found): looks up the object named "CustomWaterTool_DebugMesh" of
 * the class the pointer at 0x59385b8 holds in the registry the pointer at
 * 0x5945a38 holds (the registry's object(), FUN_00cbc5a0 with mode 0: the
 * name is made before the class is read, 0x8f348b) and pushes it through
 * FUN_00c89360; returns 1. */
extern Type00503fb0 *D_59385b8; /* the debug mesh's class */

void FUN_00c89360(lua_State *state, Object016b9108 *object); /* derived name */

int FUN_008f3440(lua_State *state) /* derived name */
{
    Object016b9108 *object = D_5945a38->object(Name("CustomWaterTool_DebugMesh"), D_59385b8);
    FUN_00c89360(state, object);
    return 1;
}

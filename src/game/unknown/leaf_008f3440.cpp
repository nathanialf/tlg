/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_hks.h"

/* derived names: a script C function (its address is not stored where a
 * table was found): looks up the object named "CustomWaterTool_DebugMesh" of
 * the class the pointer at 0x59385b8 holds in the registry the pointer at
 * 0x5945a38 holds (FUN_00cbc5a0, a last argument 0) and pushes it through
 * FUN_00c89360; returns 1. The class pointer is a const object of another
 * unit, set once by its initializer (one store in the executable, at its
 * dynamic initialization): its read is scheduled after the Name is built. */
struct Registry05945a38; /* derived name */
struct Class059385b8;    /* derived name */
struct Object00cbc5a0;   /* derived name */

extern Registry05945a38 *D_5945a38;
extern const Class059385b8 *const D_59385b8;

Object00cbc5a0 *FUN_00cbc5a0(Registry05945a38 *registry, const Class059385b8 *type,
                             const Name &name, int unknown3); /* derived name */
void FUN_00c89360(lua_State *state, Object00cbc5a0 *object);  /* derived name */

// NONMATCHING: the frame: the build saves r13 and a 0x18-byte area (the class pointer read before
// the Name is built is held across the calls); the base reads it after them. The const
// declaration, meant to free the load, does not move it
int FUN_008f3440(lua_State *state) /* derived name */
{
    Object00cbc5a0 *object =
        FUN_00cbc5a0(D_5945a38, D_59385b8, Name("CustomWaterTool_DebugMesh"), 0);
    FUN_00c89360(state, object);
    return 1;
}

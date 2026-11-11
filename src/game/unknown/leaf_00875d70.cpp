/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the script C function "Guide_Reset" (FUN_00874ec0 registers
 * it through FUN_00c87e30, lea at 0x8750e2, signature string "Guide_Reset()"):
 * passes the object the pointer at 0x581e3a8 holds and 0 to FUN_00b12fd0, then
 * the object to FUN_00b13320, and returns 0 (no results). The C function's own
 * name is unknown; the callees' return types are not traced. */
struct lua_State;
struct Object0581e3a8; /* derived name */

extern Object0581e3a8 *D_581e3a8;

void FUN_00b12fd0(Object0581e3a8 *object, int value); /* derived name */
void FUN_00b13320(Object0581e3a8 *object);            /* derived name */

int FUN_00875d70(lua_State *) /* derived name */
{
    Object0581e3a8 *object = D_581e3a8;
    FUN_00b12fd0(object, 0);
    FUN_00b13320(object);
    return 0;
}

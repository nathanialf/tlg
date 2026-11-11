/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a script C function that passes the object the pointer at
 * 0x581e3a8 holds and its state to FUN_00b14040 and returns 0 (no results);
 * the callee reads the arguments from the state. FUN_00874ec0 registers it
 * (lea at 0x875017) through FUN_00c87e30 under the script name
 * "Guide_CreateGuide" (its description
 * "Guide_CreateGuide(name,id,noruma,guide,frame,pad,type,gourpID,priority)");
 * the VM's strings name lua_State. The C function's own name is unknown. */
struct lua_State;

struct Object0581e3a8; /* derived name */

extern Object0581e3a8 *D_581e3a8;

void FUN_00b14040(Object0581e3a8 *object, lua_State *state); /* derived name */

int FUN_00875940(lua_State *state) /* derived name */
{
    FUN_00b14040(D_581e3a8, state);
    return 0;
}

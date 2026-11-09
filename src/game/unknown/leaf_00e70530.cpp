/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a script C function that returns 0 (no results). FUN_00e705b0
 * pushes it (lea at 0xe70935) through FUN_00dd6ba0, the VM's push of a named C
 * function (FUN_00c87e30's registrations call it), under the script name
 * "FlushResourceCache"; the VM's strings name lua_State. A stub in the retail
 * build. The C function's own name is unknown. */
struct lua_State;

int FUN_00e70530(lua_State *state) /* derived name */
{
    return 0;
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a script C function that returns 0 (no results). FUN_00e80560
 * pushes it (lea at 0xe80849) through FUN_00dd6ba0, the VM's push of a named C
 * function (FUN_00c87e30's registrations call it), with the function name
 * "LuaBindings::VectorNormalize2", after the key "Normalize"; the VM's strings
 * name lua_State. A stub in the retail build. The name string is the C
 * function's as the program gives it to the VM; the row keeps its FUN_ name
 * until a ruling. */
struct lua_State;

int FUN_00e7e650(lua_State *state) /* derived name */
{
    return 0;
}

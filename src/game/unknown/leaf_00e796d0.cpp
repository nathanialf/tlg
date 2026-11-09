/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* a script C function that returns 0 (no results). FUN_00e796f0
 * pushes it (lea at 0xe79849) through FUN_00dd6ba0, the VM's push of a named C
 * function (FUN_00c87e30's registrations call it), with the function name
 * "LuaBindings::ObjectClassNewIndexM", after the key "__newindex"; the VM's
 * strings name lua_State. A stub in the retail build. The name string is the C function's qualified name as the program gives it to the VM, taken as a fact (supervisor ruling, round 102A). */
struct lua_State;

namespace LuaBindings
{

int ObjectClassNewIndexM(lua_State *state)
{
    return 0;
}

} // namespace LuaBindings

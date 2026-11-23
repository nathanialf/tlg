/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lua_bindings.h"

/* LuaBindings::VectorMax3 (the name FUN_00e80560's registration gives the VM
 * for it): with two userdata arguments, the larger of each of their vectors'
 * first three floats, with the first's fourth, is pushed (FUN_00c8aa70) and
 * 1 is returned; else 0 (no results). The row keeps its FUN_ name until a
 * ruling, as leaf_00e7e520.cpp's. */
namespace LuaBindings
{

// NONMATCHING: register assignment only: the base loads the fourth float into edx
// (`mov edx, [rax + 0x2c]`), the build into eax; 58/60.
// Round 507D: the fourth float's load (a local range) is defined at the first vector's last use
// and so reuses rax; the base's edx means the first vector's pointer is still live there: in the
// base's order the w load comes before a.z's (the DAG puts it after the third max here, as the
// source's order has it).
int VectorMax3(lua_State *state)
{
    int count = state->top - state->base;
    if (count > 0 && typeOf(state, 1) == 7 && typeOf(state, 2) == 7) {
        const Float4 &a = userdataValue(state, 1);
        const Float4 &b = userdataValue(state, 2);
        Float4A r(a.x > b.x ? a.x : b.x, a.y > b.y ? a.y : b.y, a.z > b.z ? a.z : b.z, a.w);
        FUN_00c8aa70(state, &r);
        return 1;
    }
    return 0;
}

} // namespace LuaBindings

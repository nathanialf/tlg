/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* The script math library's C functions, named by its table at 0x16bcb38
 * ("abs" to "tanh", name and function in turn): each pushes the C library's
 * float function of its numbers (luaL_checknumber) and returns one result.
 * "deg", "frexp", "ldexp", "max", "min", "modf", "rad", "random" and
 * "randomseed" lie apart (0xdbf3f0 to 0xdc0190) and are not written here. */

/* "abs" */
int FUN_00de6b60(lua_State *state) /* derived name */
{
    pushNumber(state, fabsf(luaL_checknumber(state, 1)));
    return 1;
}

/* "acos" */
int FUN_00de6c40(lua_State *state) /* derived name */
{
    pushNumber(state, acosf(luaL_checknumber(state, 1)));
    return 1;
}

/* "asin" */
int FUN_00de6d20(lua_State *state) /* derived name */
{
    pushNumber(state, asinf(luaL_checknumber(state, 1)));
    return 1;
}

/* "atan" */
int FUN_00de6e00(lua_State *state) /* derived name */
{
    pushNumber(state, atanf(luaL_checknumber(state, 1)));
    return 1;
}

/* "atan2" */
int FUN_00de6ee0(lua_State *state) /* derived name */
{
    pushNumber(state, atan2f(luaL_checknumber(state, 1), luaL_checknumber(state, 2)));
    return 1;
}

/* "ceil" */
int FUN_00de7030(lua_State *state) /* derived name */
{
    pushNumber(state, ceilf(luaL_checknumber(state, 1)));
    return 1;
}

/* "cos" */
int FUN_00de7110(lua_State *state) /* derived name */
{
    pushNumber(state, cosf(luaL_checknumber(state, 1)));
    return 1;
}

/* "cosh" */
int FUN_00de71f0(lua_State *state) /* derived name */
{
    pushNumber(state, coshf(luaL_checknumber(state, 1)));
    return 1;
}

/* "exp" */
int FUN_00de72d0(lua_State *state) /* derived name */
{
    pushNumber(state, expf(luaL_checknumber(state, 1)));
    return 1;
}

/* "floor" */
int FUN_00de73b0(lua_State *state) /* derived name */
{
    pushNumber(state, floorf(luaL_checknumber(state, 1)));
    return 1;
}

/* "fmod" */
int FUN_00de7490(lua_State *state) /* derived name */
{
    pushNumber(state, fmodf(luaL_checknumber(state, 1), luaL_checknumber(state, 2)));
    return 1;
}

/* "log" */
int FUN_00de75e0(lua_State *state) /* derived name */
{
    pushNumber(state, logf(luaL_checknumber(state, 1)));
    return 1;
}

/* "log10" */
int FUN_00de76c0(lua_State *state) /* derived name */
{
    pushNumber(state, log10f(luaL_checknumber(state, 1)));
    return 1;
}

/* "pow" */
int FUN_00de77a0(lua_State *state) /* derived name */
{
    pushNumber(state, powf(luaL_checknumber(state, 1), luaL_checknumber(state, 2)));
    return 1;
}

/* "sqrt" */
int FUN_00de78f0(lua_State *state) /* derived name */
{
    pushNumber(state, sqrtf(luaL_checknumber(state, 1)));
    return 1;
}

/* "sin" */
int FUN_00de79f0(lua_State *state) /* derived name */
{
    pushNumber(state, sinf(luaL_checknumber(state, 1)));
    return 1;
}

/* "sinh" */
int FUN_00de7ad0(lua_State *state) /* derived name */
{
    pushNumber(state, sinhf(luaL_checknumber(state, 1)));
    return 1;
}

/* "tan" */
int FUN_00de7bb0(lua_State *state) /* derived name */
{
    pushNumber(state, tanf(luaL_checknumber(state, 1)));
    return 1;
}

/* "tanh" */
int FUN_00de7c90(lua_State *state) /* derived name */
{
    pushNumber(state, tanhf(luaL_checknumber(state, 1)));
    return 1;
}

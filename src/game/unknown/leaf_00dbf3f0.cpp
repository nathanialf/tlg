/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* The script math library's C functions that lie apart from the others
 * (leaf_00de6c40.cpp), named by its table at 0x16bcb38 (name and function in
 * turn): "deg", "frexp", "ldexp", "max", "min", "modf", "rad" and "random". Each reads
 * its numbers as Lua 5.1's lmathlib.c does and pushes its results. */

/* the degrees in a radian's turn and back: the float of pi / 180 (0x3c8efa35;
 * deg multiplies by its reciprocal 0x42652ee1) */
static const float RADIANS_PER_DEGREE = 3.14159265f / 180.0f; /* derived name */

/* luaL_checknumber and luaL_checkinteger (their assertions' names) as
 * functions of their own, the argument resolved through any pseudo-index;
 * their bodies are not written */
float FUN_00dbf4d0(lua_State *s, int argument);
int FUN_00dbf960(lua_State *s, int argument);

/* "deg" */
int FUN_00dbf3f0(lua_State *state) /* derived name */
{
    pushNumber(state, luaL_checknumber(state, 1) / RADIANS_PER_DEGREE);
    return 1;
}

/* "frexp": the mantissa and the exponent */
int FUN_00dbf760(lua_State *state) /* derived name */
{
    int exponent;
    pushNumber(state, frexpf(luaL_checknumber(state, 1), &exponent));
    pushInteger(state, exponent);
    return 2;
}

/* "ldexp" */
int FUN_00dbf870(lua_State *state) /* derived name */
{
    pushNumber(state, ldexpf(luaL_checknumber(state, 1), FUN_00dbf960(state, 2)));
    return 1;
}

/* "max": the largest of its arguments */
int FUN_00dbfbd0(lua_State *state) /* derived name */
{
    int n = argumentCount(state);
    float largest = luaL_checknumber(state, 1);
    for (int i = 2; i <= n; i++) {
        float d = FUN_00dbf4d0(state, i);
        if (d > largest)
            largest = d;
    }
    pushNumber(state, largest);
    return 1;
}

/* "min": the smallest of its arguments */
int FUN_00dbfd00(lua_State *state) /* derived name */
{
    int n = argumentCount(state);
    float smallest = luaL_checknumber(state, 1);
    for (int i = 2; i <= n; i++) {
        float d = FUN_00dbf4d0(state, i);
        if (d < smallest)
            smallest = d;
    }
    pushNumber(state, smallest);
    return 1;
}

/* "modf": the whole part and the fraction */
int FUN_00dbfe30(lua_State *state) /* derived name */
{
    float whole;
    float fraction = modff(luaL_checknumber(state, 1), &whole);
    pushNumber(state, whole);
    pushNumber(state, fraction);
    return 2;
}

/* "rad" */
int FUN_00dbff40(lua_State *state) /* derived name */
{
    pushNumber(state, luaL_checknumber(state, 1) * RADIANS_PER_DEGREE);
    return 1;
}

/* "random": a number in [0, 1), or an integer in [1, u] or [l, u] */
int FUN_00dc0020(lua_State *state) /* derived name */
{
    float r = (float)(rand() % RAND_MAX) / (float)RAND_MAX;
    int n = argumentCount(state);
    if (n == 0) {
        pushNumber(state, r);
    } else if (n == 1) {
        float u = FUN_00dbf960(state, 1);
        if (!(1 <= u))
            FUN_00dd3450(state, 1, "interval is empty");
        pushNumber(state, floorf(r * u) + 1);
    } else if (n >= 2) {
        float l = FUN_00dbf960(state, 1);
        float u = FUN_00dbf960(state, 2);
        if (!(l <= u))
            FUN_00dd3450(state, 2, "interval is empty");
        pushNumber(state, floorf(r * (u - l + 1)) + l);
    }
    return 1;
}

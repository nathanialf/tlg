/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks_string.h"
#include "tlg_libc.h"

/* LuaBindings::VectorToString and LuaBindings::VectorToString2 (the names
 * FUN_00e80560 gives the VM for them through FUN_00dd6ba0, the first under
 * the key "__tostring", lea at 0xe81352): with an argument that is a
 * userdata (type 7), its vector's four (two) floats are formatted with
 * "%g %g %g %g" ("%g %g") into a local buffer whose string is pushed
 * (FUN_013aacc0 with its length), and 1 is returned; else 0 (no results).
 * The rows keep their FUN_ names until a ruling, as the stubs beside them
 * (leaf_00e7e5e0.cpp). derived names otherwise. */
struct VectorUserdata00e7e520 { /* derived name */
    u8 unknown0[0x20];          /* the userdata's header, not traced */
    float x;                    /* +0x20 */
    float y;
    float z;
    float w;
};

namespace LuaBindings
{

// NONMATCHING: the base folds each float's load into `vcvtss2sd` (memory form) after a
// `vxorps` of the pass-through register; the build loads with `vmovss` and converts registers
// (the conversions' undefined pass-through operand, NOTES round 260A item 1: region-wide)
int VectorToString(lua_State *state)
{
    int count = state->top - state->base;
    if (count > 0 && typeOf(state, 1) == 7) {
        const VectorUserdata00e7e520 *vector =
            static_cast<const VectorUserdata00e7e520 *>(state->base->value.pointer);
        char text[128];
        sprintf(text, "%g %g %g %g", vector->x, vector->y, vector->z, vector->w);
        FUN_013aacc0(state, text, strlen(text));
        return 1;
    }
    return 0;
}

// NONMATCHING: the base folds each float's load into `vcvtss2sd` (memory form) after a
// `vxorps` of the pass-through register; the build loads with `vmovss` and converts registers
// (the conversions' undefined pass-through operand, NOTES round 260A item 1: region-wide)
int VectorToString2(lua_State *state)
{
    int count = state->top - state->base;
    if (count > 0 && typeOf(state, 1) == 7) {
        const VectorUserdata00e7e520 *vector =
            static_cast<const VectorUserdata00e7e520 *>(state->base->value.pointer);
        char text[128];
        sprintf(text, "%g %g", vector->x, vector->y);
        FUN_013aacc0(state, text, strlen(text));
        return 1;
    }
    return 0;
}

} // namespace LuaBindings

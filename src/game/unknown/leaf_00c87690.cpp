/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_sce_pad.h"

/* derived names: the script C functions "ResetLightBar" (lea at 0xc8504b)
 * and "ResetOrientation" (lea at 0xc85243): with exactly one argument, its
 * number as an int selects a pad record in the array of pointers at +0x98
 * of the object the pointer at 0x5938c40 holds, whose pad handle at +0x20
 * goes to the pad library's reset; they return 0 (no results). The record's
 * other fields and the array's extent are not traced. */
struct Pad05938c40 { /* derived name */
    u8 unknown0[0x20];
    int handle; /* +0x20 */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x98];
    Pad05938c40 *pads[1]; /* +0x98 */
};

extern Object05938c40 *D_5938c40;

int FUN_00c87690(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count == 1) {
        int pad = toNumber(state, 1);
        scePadResetLightBar(D_5938c40->pads[pad]->handle);
    }
    return 0;
}

/* "SetTiltCorrectionState" (lea at 0xc850f3) and
 * "SetAngularVelocityDeadbandState" (lea at 0xc8519b): with exactly two
 * arguments, the first's number as an int selects the pad record as above
 * and the second's truth goes to the pad library with the record's handle;
 * they return 0. */
// NONMATCHING: the second argument's truth, as leaf_0046b050.cpp's: the base keeps the slot a
// select of null past the top (`cmovae rsi, rdx; jae`) and reads the tag through it, the build
// folds the select into the branch (`lea rdx, [rsi + 0x10]; cmp; jae`)
int FUN_00c876e0(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count == 2) {
        int pad = toNumber(state, 1);
        bool enable = toBoolean(state, 2);
        scePadSetTiltCorrectionState(D_5938c40->pads[pad]->handle, enable);
    }
    return 0;
}

// NONMATCHING: the second argument's truth, as leaf_0046b050.cpp's: the base keeps the slot a
// select of null past the top (`cmovae rsi, rdx; jae`) and reads the tag through it, the build
// folds the select into the branch (`lea rdx, [rsi + 0x10]; cmp; jae`)
int FUN_00c87770(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count == 2) {
        int pad = toNumber(state, 1);
        bool enable = toBoolean(state, 2);
        scePadSetAngularVelocityDeadbandState(D_5938c40->pads[pad]->handle, enable);
    }
    return 0;
}

int FUN_00c87800(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count == 1) {
        int pad = toNumber(state, 1);
        scePadResetOrientation(D_5938c40->pads[pad]->handle);
    }
    return 0;
}

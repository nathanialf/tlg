/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"
#include "tlg_sce_pad.h"

/* derived names: a pad record of the array at +0x98 of the object the
 * pointer at 0x5938c40 holds (leaf_00c87690.cpp): its handle at +0x20 and
 * the two motors' strengths last set, 0 to 1. The rest is not traced. */
/* derived name: a value clamped to [low, high], by reference */
template <class T> static inline const T &clamp00c87210(const T &value, const T &low, const T &high)
{
    return value < low ? low : (value < high ? value : high);
}

struct Pad00c87210 { /* derived name */

    /* derived name: the motors' strengths kept between 0 and 1, and the pad
     * vibrating at them scaled to 255 */
    void vibrate(float large, float small)
    {
        largeMotor = clamp00c87210(large, 0.0f, 1.0f);
        smallMotor = clamp00c87210(small, 0.0f, 1.0f);
        PadVibration vibration;
        vibration.largeMotor = largeMotor * 255.0f;
        vibration.smallMotor = smallMotor * 255.0f;
        scePadSetVibration(handle, &vibration);
    }

    u8 unknown0[0x20];
    int handle; /* +0x20 */
    u8 unknown24[0x24];
    float smallMotor; /* +0x48 */
    float largeMotor; /* +0x4c */
};

struct Object00c87210 { /* derived name */
    u8 unknown0[0x98];
    Pad00c87210 *pads[1]; /* +0x98 */
};

extern Object00c87210 *D_5938c40;

/* derived names: a script C function FUN_00c83870 registers (lea at
 * 0xc84dab): with exactly three arguments, the first's number as an int
 * selects the pad record, which vibrates at the second and third (its large
 * and small motors); returns 0 (no results). */
int FUN_00c87210(lua_State *state) /* derived name */
{
    int count = ((char *)state->top - (char *)state->base) / sizeof(HksObject);
    if (count == 3) {
        int pad = toNumber(state, 1);
        float large = toNumber(state, 2);
        float small = toNumber(state, 3);
        D_5938c40->pads[pad]->vibrate(large, small);
    }
    return 0;
}

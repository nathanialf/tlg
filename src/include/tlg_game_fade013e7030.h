/* src/include/tlg_game_fade013e7030.h: the sine fade that slot 3 of 25 track
 * classes steps (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_FADE013E7030_H
#define TLG_GAME_FADE013E7030_H

#include "tlg_libc.h"
#include "tlg_types.h"

#include <algorithm>

/* derived names: the control a fade reads at +0x10 of its object: the
 * direction, a state the fade writes back, a restart flag and the step. */
struct FadeControl013e7030 { /* derived name */
    int direction;           /* +0x0: 1 fading in */
    int state;               /* +0x4 */
    int restart;             /* +0x8 */
    u8 unknownc[0x8];
    float step; /* +0x14 */
};

/* derived names: the fields slot 3 of the track classes reads and writes:
 * the control at +0x10, the value at +0x60, the time at +0x64 over the length
 * at +0x68 and the restart seen at +0x6c. The classes are not traced. */
struct Object013e7030 { /* derived name */
    u8 unknown0[0x10];
    FadeControl013e7030 *control; /* +0x10 */
    u8 unknown18[0x48];
    float value;    /* +0x60 */
    float time;     /* +0x64 */
    float duration; /* +0x68 */
    int restarted;  /* +0x6c */
};

namespace fade013e7030
{ /* derived name */

/* The bounds by reference: the 1.0's temporary is stored before the low
 * test, and the chosen address is loaded (`cmovb rax, rcx; vmovss xmm1,
 * [rax]`): the time's own load is not in the block, so the select of the two
 * addresses is not speculated (Loads.cpp isSafeToLoadUnconditionally). */
template <typename T> inline T clamp(const T &value, const T &low, const T &high) /* derived name */
{
    if (value < low)
        return low;
    return std::min(high, value);
}

inline float easeInSine(float x) /* derived name */
{
    if (x <= 0.0f)
        return 0.0f;
    if (x >= 1.0f)
        return 1.0f;
    return 1.0f - sin((1.0f - x) * 1.57079637f);
}

inline float easeOutSine(float x) /* derived name */
{
    if (x <= 0.0f)
        return 0.0f;
    if (x >= 1.0f)
        return 1.0f;
    return sin(x * 1.57079637f);
}

} // namespace fade013e7030

#endif

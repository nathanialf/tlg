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

/* derived names: the object at +0x8 of a track that some slot 3 variants
 * read: the control at +0x228 (its state at +0x4 and restart at +0x8 tested
 * against 1, FUN_013fca70). The rest is not traced. */
struct Owner013fca70 { /* derived name */
    u8 unknown0[0x228];
    FadeControl013e7030 *control; /* +0x228 */
};

/* derived names: the fields slot 3 of the track classes reads and writes:
 * the control at +0x10, the value at +0x60, the time at +0x64 over the length
 * at +0x68 and the restart seen at +0x6c. The classes are not traced. */
struct Object013e7030 { /* derived name */
    u8 unknown0[0x8];
    Owner013fca70 *owner;         /* +0x8: read by the variants only */
    FadeControl013e7030 *control; /* +0x10 */
    u8 unknown18[0x48];
    float value;    /* +0x60 */
    float time;     /* +0x64 */
    float duration; /* +0x68 */
    int restarted;  /* +0x6c */
};

/* derived names: the owner of the tracks whose slot 3 is FUN_01407460: the
 * control at +0x230. The rest is not traced. */
struct Owner01407460 { /* derived name */
    u8 unknown0[0x230];
    FadeControl013e7030 *control; /* +0x230 */
};

/* derived names: Object013e7030's fields under that owner (FUN_01407460) */
struct Object01407460 { /* derived name */
    u8 unknown0[0x8];
    Owner01407460 *owner;         /* +0x8 */
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

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"
#include "tlg_types.h"

/* derived names: a value with its y taken from a curve at the position's
 * z: the value copied whole; with no keys nothing more; the first key's
 * value with one key or before the first key's time, the last key's after
 * the last key's time, otherwise the value interpolated linearly between
 * the key before the position and the first key after it. A key is 16
 * bytes, its value at +0x4 and its time at +0xc. Called by FUN_010913b0. */
struct CurveKey010a0670 { /* derived name */
    float unknown0;
    float value; /* +0x4 */
    float unknown8;
    float time; /* +0xc */
};

struct Curve010a0670 {            /* derived name */
    const CurveKey010a0670 *keys; /* +0x0 */
    int count;                    /* +0x8 */
};

// NONMATCHING: the search. The base loads the next key's time before the
// count's test (a down-counter, `test esi, esi; je`), compares after it and
// keeps that time for the interpolation, the key before found by an index
// kept in the high half (`add rdx, 1 << 32; sar rdx, 0x1c`) and the key
// after by the walking pointer (`[rcx - 0x18]`); this build tests the count
// first and reloads both keys by index. The early answers' blocks are laid
// out differently (the first key's value last in the base); 185 bytes
// against 188.
void FUN_010a0670(Float4A *out, const Float4A *value, const Float4 *position,
                  const Curve010a0670 *curve) /* derived name */
{
    *out = *value;
    int count = curve->count;
    if (count == 0)
        return;
    const CurveKey010a0670 *keys = curve->keys;
    float t = position->z;
    if (count == 1 || t < keys[0].time) {
        out->y = keys[0].value;
        return;
    }
    if (t > keys[count - 1].time) {
        out->y = keys[count - 1].value;
        return;
    }
    int i = 1;
    while (i < count - 1 && !(t < keys[i].time))
        ++i;
    const CurveKey010a0670 &a = keys[i - 1];
    const CurveKey010a0670 &b = keys[i];
    out->y = (b.value - a.value) * ((t - a.time) / (b.time - a.time)) + a.value;
}

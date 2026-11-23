/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the curve's ten points, their inputs and their values,
 * rising from (0, 0); the curve ends at (1, 1). The unit holds them: the
 * last segment's slope is folded from them ((1 - 0.68085) / (1 - 0.97875),
 * 0x41704d11 at 0x14e12fc) */
extern const float D_1524870[10];
const float D_1524870[10] = {
#include "gen/D_1524870.inc"
};
extern const float D_15248a0[10];
const float D_15248a0[10] = {
#include "gen/D_15248a0.inc"
};

/* derived name: a value clamped to [low, high], by reference */
template <class T> static inline const T &clamp011e52f0(const T &value, const T &low, const T &high)
{
    return value < low ? low : (value < high ? value : high);
}

/* derived name: the curve at t, clamped to [0, 1]: linear between the
 * points the inputs bracket, to (1, 1) past the last. Its one caller is
 * FUN_011dd5c0. */
float FUN_011e52f0(float t) /* derived name */
{
    t = clamp011e52f0(t, 0.0f, 1.0f);
    unsigned i = 0;
    while (i < 9 && t >= D_1524870[i + 1])
        ++i;
    float offset;
    float slope;
    if (i == 9) {
        offset = t - D_1524870[9];
        slope = (1.0f - D_15248a0[9]) / (1.0f - D_1524870[9]);
    } else {
        offset = t - D_1524870[i];
        slope = (D_15248a0[i + 1] - D_15248a0[i]) / (D_1524870[i + 1] - D_1524870[i]);
    }
    return D_15248a0[i] + slope * offset;
}

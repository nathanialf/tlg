/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a value blended toward a new one when the handle it
 * follows changes: the value and the one before at +0x0 and +0x4, the
 * handle and the one before at +0x8 and +0x10 (-1 none), the blend's time
 * and rate at +0x18 and +0x1c, whether it changed this step at +0x20, a
 * flag at +0x24 that keeps it while there is no handle, whether the handle
 * was dropped this step at +0x28 and the length at +0x2c */
struct Blend013fa580 { /* derived name */

    /* derived name: everything cleared, the current value and handle and
     * then the previous ones, the handles none and the rate one over the
     * length (zero for none) */
    void reset()
    {
        value = 0.0f;
        handle = -1;
        previous = 0.0f;
        previousHandle = -1;
        time = 0.0f;
        changed = 0;
        rate = duration != 0.0f ? 1.0f / duration : 0.0f;
    }

    float value;        /* +0x0 */
    float previous;     /* +0x4 */
    s64 handle;         /* +0x8 */
    s64 previousHandle; /* +0x10 */
    float time;         /* +0x18 */
    float rate;         /* +0x1c */
    int changed;        /* +0x20 */
    int keep;           /* +0x24 */
    int dropped;        /* +0x28 */
    float duration;     /* +0x2c */
};

/* derived name: the value clamped to [low, high], by reference */
template <class T> static inline const T &clamp013fa580(const T &value, const T &low, const T &high)
{
    return value < low ? low : (value < high ? value : high);
}

/* derived names: steps the blend by `step`: a dropped handle resets it
 * unless kept, a new one starts the blend from the value before, and the
 * value is the previous one and the current one mixed by the time; the
 * value is given back and kept as the one before. Its callers are
 * FUN_013f9e20, FUN_01474cc0, FUN_01489ca0, FUN_0148ac70 and FUN_0148b730. */
// NONMATCHING: 82/84 at the base's 359 bytes: the two copies into the
// step's phis on the handle's change (`vxorps xmm1; mov ecx, 1` in the base,
// the other order here). The time set to 1 skips the step's test (its own
// edge into the copy, so the copy's loads are not PRE'd), and reset()
// stores the current value and handle, then the previous ones (the two
// handles one 16-byte store, the values two dwords).
void FUN_013fa580(Blend013fa580 *self, float step, float *out) /* derived name */
{
    self->changed = 0;
    const s64 handle = self->handle;
    const s64 previousHandle = self->previousHandle;
    self->dropped = handle == -1 && previousHandle != -1;
    if (handle == -1 && !self->keep) {
        self->reset();
        return;
    }
    if (previousHandle == -1 && !self->keep)
        self->time = 1.0f;
    else {
        if (previousHandle != handle) {
            self->time = 0.0f;
            self->changed = 1;
        }
        if (self->time < 1.0f) {
            if (self->rate == 0.0f)
                self->time = 1.0f;
            else if (!self->changed) {
                self->time += self->rate * step;
                self->time = clamp013fa580(self->time, 0.0f, 1.0f);
            }
            self->value = self->previous * (1.0f - self->time) + self->value * self->time;
        }
    }
    *out = self->value;
    self->previous = self->value;
    self->previousHandle = self->handle;
}

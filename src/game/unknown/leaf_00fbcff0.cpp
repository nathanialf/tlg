/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: moves a value toward a target at 60 frames a second (the
 * constant 59.999996), the whole frames of the step one at a time and the
 * fraction left as a part of one, by a rate read from an eleven-entry table
 * (D_15251c0, 0.013 to 0.57 and 0) at a speed clamped to 0..10 and
 * interpolated between two entries; the value is set to the target when the
 * two are closer than 1e-10. FUN_0101e320 (leaf_0101e320.cpp) is the same
 * walk at a fixed rate of 0.11. Twelve other units hold a copy of these
 * bytes over their own constants (0xfdac40, 0x1047160, 0x10c3260, 0x10d48e0,
 * 0x10f2570, 0x11c9730, 0x11e5140, 0x124b620, 0x128e1e0, 0x12a78e0,
 * 0x12cf0d0, 0x12e0750), each called only from its own unit. */
extern const float D_15251c0[11]; /* derived: the rates by speed */

// NONMATCHING: greedy's assignment and list-ilp order, as leaf_0101e320.cpp's: the base's
// difference pair in xmm6/xmm7 the other way at the entry, and the base takes the clamp's
// `vminss` before the `vcmpltss` and converts the index after `inc` (two registers for the
// index and the next one, the build one); every operation else the same (4 of 46 by position)

void FUN_00fbcff0(float *value, float target, float speed, float step) /* derived name */
{
    float distance = target - *value > 0.0f ? target - *value : *value - target;
    if (distance >= 1e-10f) {
        speed = speed < 0.0f ? 0.0f : (speed < 10.0f ? speed : 10.0f);
        unsigned index = (unsigned)speed;
        if (index == 10)
            index = 9;
        float part = speed - (float)index;
        float rate = (1.0f - part) * D_15251c0[index] + part * D_15251c0[index + 1];
        float frames = step * 59.999996f;
        int whole = (int)frames;
        float fraction = frames - (float)whole;
        while (whole-- > 0)
            *value = *value + (target - *value) * rate;
        *value = *value + fraction * rate * (target - *value);
    } else {
        *value = target;
    }
}

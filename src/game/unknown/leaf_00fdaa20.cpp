/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_vector00fdab40.h"

/* A table of 16 floats, 0.12 rising by 0.04 to 0.72 (leaf_00fdadf0.cpp). */
extern const float D_1524a00[16];

/* derived names: FUN_00fdadf0's step of a value toward a target
 * (leaf_00fdadf0.cpp) over a vector: the factor read from the table at the
 * time clamped to [0, 15], the value's change since the previous step kept,
 * the new value and the previous one written back.
 * The pull is the target's difference scaled by 13 / rate, one division
 * placed after the target's lanes are read (Reassociate ranks a division by
 * its place in the block: 13 / rate then outranks the first three lanes'
 * sums, and each lane is (sum * rate * rate) * (13 / rate) with rate * rate
 * evaluated first, as the base has it; a division by rate before the scale
 * by 13 leaves 13 with rate * rate, and 13 / rate evaluated before the
 * target merges it with rate * rate into one scalar).
 * The stiffness, rate * rate, is computed before the value is read: the
 * allocator then gives it the register before the change since the previous
 * step, and the fourth lane's sum, finding no cheap register free, evicts
 * the stiffness (the lighter range) rather than the change, as the base has
 * it (the change in xmm4, the fourth lane's sum in xmm3). */
void FUN_00fdaa20(Vector4Loop *value, Vector4Loop *previous, const Vector4Loop &target, float time,
                  float rate) /* derived name */
{
    float clamped = time < 15.0f ? time : 15.0f;
    if (time < 0.0f)
        clamped = 0.0f;
    unsigned index = (unsigned)clamped;
    if (index == 15)
        index = 14;
    float fraction = clamped - (float)index;
    float factor = D_1524a00[index] * (1.0f - fraction) + D_1524a00[index + 1] * fraction;
    float stiffness = rate * rate;
    Vector4Loop current = *value;
    Vector4Loop delta = current - *previous;
    *value = factor * (stiffness * ((target - current - delta) * (13.0f / rate)) + delta) + current;
    *previous = current;
}

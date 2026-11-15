/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: one step over three float arrays of the first array's
 * count, each value moved by its change since the previous step and the
 * third array's term, the step's length scaled by 13 over it, then that times
 * a constant added (0x3ed70a3e, one unit above 0.42f: written as the sum
 * 0.4f + 0.02f, which gives it, as 0.4f + 2 * 0.02f gives FUN_010f1c30's
 * 0.44f; other sums and products of two constants give it too, so the
 * terms are not a fact); the previous values are kept in the second array. FUN_010f1c30
 * (leaf_010f1c30.cpp) has the same instructions with 0.44. What the arrays hold is not traced. */
struct FloatArray0113f670 { /* derived name */
    float *data;
    unsigned count;

    float &at(int index)
    {
        return data[index];
    } /* derived name */
};

/* the counter is unsigned and the table's index an int: the index is sign-extended at each
 * use (`movsxd`), not widened */
void FUN_0113f670(FloatArray0113f670 *current, FloatArray0113f670 *previous,
                  FloatArray0113f670 *term, float step) /* derived name */
{
    float rate = 13.0f / step;
    float scale = step * step * rate;
    unsigned count = current->count;
    for (unsigned i = 0; i < count; ++i) {
        float value = current->at(i);
        float change = value - previous->at(i);
        float force = term->at(i) - value - change;
        previous->at(i) = value;
        current->at(i) += (scale * force + change) * (0.4f + 0.02f);
    }
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: one step over three float arrays of the first array's
 * count, each value moved by its change since the previous step and the
 * third array's term, the step's length scaled by 13 over it, then 0.44 of
 * that added; the previous values are kept in the second array. Called
 * once, from 0x10ecdb4; FUN_0113f670 (leaf_0113f670.cpp, called from
 * 0x1126ff1) has the same bytes. What the arrays hold is not traced. */
struct FloatArray010f1c30 { /* derived name */
    float *data;
    unsigned count;
};

// NONMATCHING: IndVarSimplify: the base keeps the int index and sign-extends it each
// iteration (`movsxd rcx, ecx`, `test r8d, r8d`), the build widens it (`test r8, r8`); 1 of 31
void FUN_010f1c30(FloatArray010f1c30 *current, FloatArray010f1c30 *previous,
                  FloatArray010f1c30 *term, float step) /* derived name */
{
    float scale = step * step * (13.0f / step);
    unsigned count = current->count;
    for (int i = 0; i < count; ++i) {
        float value = current->data[i];
        float change = value - previous->data[i];
        float force = -value - change + term->data[i];
        previous->data[i] = value;
        current->data[i] += (scale * force + change) * 0.44f;
    }
}

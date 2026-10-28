/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The result a linear row reads when the runtime has none for it (a
 * file-local object, zero, D17). */
static hkpSolverResults D_57c8840;

/* derived name: slot 19 of hkp6DofConstraintData's vtable (address point
 * 0x16a5d30): the impulses of the three linear results as a vector. */
void hkp6DofConstraintData::FUN_0017ca80(const void *argument1, const void *argument2,
                                         const hkpSolverResults *results, Vec4 &out) const
{
    const float x =
        (resultToRuntime[0] >= 0 ? results[resultToRuntime[0]] : D_57c8840).impulseApplied;
    const float y =
        (resultToRuntime[1] >= 0 ? results[resultToRuntime[1]] : D_57c8840).impulseApplied;
    const float z =
        (resultToRuntime[2] >= 0 ? results[resultToRuntime[2]] : D_57c8840).impulseApplied;
    out = _mm_setr_ps(x, y, z, 0.0f);
}

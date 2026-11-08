/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

float hkQuaternion::FUN_0001a0a0() const /* derived name */
{
    const Vec4 absW = hkMath::quadFabs(_mm_shuffle_ps(vec, vec, _MM_SHUFFLE(3, 3, 3, 3)));
    const Vec4 acos = _mm_sub_ps(D_14b4310, hkMath::quadAsin(absW));
    return _mm_cvtss_f32(_mm_add_ps(acos, acos));
}

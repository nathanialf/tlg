/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <xmmintrin.h>

#include "tlg_hk_reflect.h"

void hknpShapeInstance::FUN_0003ea90(hkTransform &transformOut) const
{
    transformOut.rotation.col0 =
        _mm_mul_ps(_mm_shuffle_ps(scale, scale, _MM_SHUFFLE(0, 0, 0, 0)), transform.rotation.col0);
    transformOut.rotation.col1 =
        _mm_mul_ps(_mm_shuffle_ps(scale, scale, _MM_SHUFFLE(1, 1, 1, 1)), transform.rotation.col1);
    transformOut.rotation.col2 =
        _mm_mul_ps(_mm_shuffle_ps(scale, scale, _MM_SHUFFLE(2, 2, 2, 2)), transform.rotation.col2);
    transformOut.translation = transform.translation;
}

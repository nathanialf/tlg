/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_hk_reflect.h"

void hknpShapeInstance::FUN_0003ec40(const hkTransform &newTransform)
{
    const int index = getIndex();
    const int size = getShapeSize();
    int flags = getFlags() & ~(HAS_TRANSLATION | HAS_ROTATION);
    transform = newTransform;
    const __m128i xyz = _mm_setr_epi32(-1, -1, -1, 0);
    const __m128i zero = _mm_castps_si128(_mm_cmpeq_ps(newTransform.translation, _mm_setzero_ps()));
    if (!_mm_testc_si128(_mm_and_si128(zero, xyz), xyz)) {
        flags |= HAS_TRANSLATION;
    }
    if (!newTransform.rotation.FUN_0001ad50(identityRotation(), 0.001f)) {
        flags |= HAS_ROTATION;
    }
    setFlags(flags);
    setShapeSize(size);
    setIndex(index);
}

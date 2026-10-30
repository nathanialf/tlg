/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkpLinearParametricCurve::FUN_0007fb50(float t, Vec4 &binormal) const
{
    Vec4 tangent;
    FUN_0007f870(t, tangent);
    if (_mm_cvtss_f32(_mm_dp_ps(tangent, D_14b2060[30], 0x7f)) < 0.98f) {
        binormal = cross3(tangent, dirNotParallelToTangentAlongWholePath);
    } else {
        /* The perpendicular is permuted in the integer unit and stored as an
         * integer vector (cookbook 301). */
        _mm_store_si128(reinterpret_cast<__m128i *>(&binormal),
                        _mm_castps_si128(perpendicular3(tangent)));
    }
    binormal = normalized3(binormal);
}

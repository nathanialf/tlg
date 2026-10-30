/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpMotion::FUN_00157350(hkMatrix3 &inertiaOut) const
{
    hkMatrix3 rotation;
    rotation.FUN_0000bd30(orientation);
    const Vec4 inertia = reciprocalOrZero(loadHalves(inverseInertia));
    hkMatrix3 scaled;
    scaled.col0 = _mm_mul_ps(broadcast<0>(inertia), rotation.col0);
    scaled.col1 = _mm_mul_ps(broadcast<1>(inertia), rotation.col1);
    scaled.col2 = _mm_mul_ps(broadcast<2>(inertia), rotation.col2);
    inertiaOut.FUN_0001abb0(scaled, rotation);
}

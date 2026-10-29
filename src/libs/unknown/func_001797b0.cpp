/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpVehicleLinearCastWheelCollide::FUN_001797b0(const hknpVehicleInstance *vehicle,
                                                     u8 wheelIndex, Vec4 &point) const
{
    const hkTransform &transform = wheelStates.data[wheelIndex].transform;
    Vec4 local;
    FUN_00010f90(local, transform, point);
    local = _mm_blend_ps(local, _mm_setzero_ps(), 4);
    Vec4 result;
    FUN_00010f50(result, transform, local);
    point = result;
}

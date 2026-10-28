/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpVehicleInstance::FUN_00162db0(const void *argument1, Slot16Output &out) const
{
    out.flag1 = false;
    out.flag0 = true;
    out.value8 = 0;
    out.vector70 = _mm_setzero_ps();
    out.vector20 = _mm_setzero_ps();
    out.vector10 = _mm_setzero_ps();
    out.unknown38 = 0;
    out.unknown30 = 0;
    out.rotation.col0 = D_14b2060[29];
    out.rotation.col1 = D_14b2060[30];
    out.rotation.col2 = D_14b2060[31];
}

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkMatrix3::FUN_0001aaa0(const hkMatrix3 &r)
{
    hkMatrix3 temp;
    temp.setMulTransposed(*this, r);
    setMul(r, temp);
}

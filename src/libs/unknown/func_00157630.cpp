/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpMotion::FUN_00157630(const Vec4 &newAngularVelocity)
{
    angularVelocity = rotatedInverseDir(orientation, newAngularVelocity);
}

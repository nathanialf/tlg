/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The base inlines setFromRotation; 3.3 refused it under -g until D33 (the
 * callee's debug intrinsics no longer count toward the vector bonus). */
void hkMatrix3::FUN_0000bf40() /* derived name */
{
    hkQuaternion q;
    q.setFromRotation(*this);
    q.normalize();
    setRotation(q);
}

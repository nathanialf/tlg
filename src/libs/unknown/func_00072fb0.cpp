/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hknpCapsuleShape *hknpCapsuleShape::FUN_00072fb0(const Vec4 &a_, const Vec4 &b_, float radius)
{
    const int numBytes = FUN_001542f0(8, 6, 24, sizeof(hknpCapsuleShape));
    void *storage = D_16dc070->temp58->blockAlloc(numBytes);
    hknpCapsuleShape *capsule = new (storage) hknpCapsuleShape(radius);
    capsule->FUN_00073260(a_, b_);
    capsule->setMemSize(numBytes);
    return capsule;
}

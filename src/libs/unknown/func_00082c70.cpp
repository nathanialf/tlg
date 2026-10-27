/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkpRagdollConstraintData::hkpRagdollConstraintData(hkFinishLoadedObjectFlag flag)
    : hkpConstraintData(flag), atoms(flag)
{
    if (flag.finishing && atoms.coneLimit.memOffsetToAngleOffset) {
        FUN_0007dad0(true);
    }
}

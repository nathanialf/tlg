/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Turn the cone limit's stabilization on or off: when on, the cone keeps its
 * angle offset 16 bytes into the constraint's runtime. */
void hkpRagdollLimitsData::FUN_0007c860(hkBool enable) /* derived name */
{
    atoms.coneLimit.memOffsetToAngleOffset = enable ? 16 : 0;
}

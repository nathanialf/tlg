/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Turn the cone limit's stabilization on or off: when on, the cone keeps its
 * angle offset 56 bytes into the constraint's runtime. Run by the finish
 * callback (0x82cb6) when the loaded offset is nonzero. */
void hkpRagdollConstraintData::FUN_0007dad0(hkBool enable) /* derived name */
{
    atoms.coneLimit.memOffsetToAngleOffset = enable ? 56 : 0;
}

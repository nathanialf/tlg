/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The finish constructor of hknpMalleableConstraintData (its type info's
 * callback 0x615c0 runs it): the wrapped data's, then, when finishing, the
 * atom bridged to this object again with its solver results counted. */
hknpMalleableConstraintData::hknpMalleableConstraintData(hkFinishLoadedObjectFlag flag)
    : hkpWrappedConstraintData(flag)
{
    if (flag.finishing) {
        bridgeAtom(wantsRuntime);
    }
}

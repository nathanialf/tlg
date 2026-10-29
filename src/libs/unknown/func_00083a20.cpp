/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkBool hkpLinearClearanceConstraintData::unknownVirtual7() const
{
    return atoms.transforms.transformA.rotation.FUN_0000bde0() &&
           atoms.transforms.transformB.rotation.FUN_0000bde0() &&
           atoms.linLimit0.min <= atoms.linLimit0.max &&
           atoms.linLimit1.min <= atoms.linLimit1.max &&
           atoms.linLimit2.min <= atoms.linLimit2.max && atoms.ang.numConstrainedAxes < 4;
}

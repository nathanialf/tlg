/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpLimitedHingeConstraintData's destructor (slot 0 of its vtable): the
 * motor's reference given back. */
hkpLimitedHingeConstraintData::~hkpLimitedHingeConstraintData()
{
    if (atoms.angMotor.motor) {
        atoms.angMotor.motor->removeReference();
    }
}

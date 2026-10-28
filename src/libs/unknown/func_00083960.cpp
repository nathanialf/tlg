/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkpLinearClearanceConstraintData's destructor (slot 0 of its vtable): the
 * motor's reference given back. */
hkpLinearClearanceConstraintData::~hkpLinearClearanceConstraintData()
{
    if (atoms.motor.motor) {
        atoms.motor.motor->removeReference();
    }
}

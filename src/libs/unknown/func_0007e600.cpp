/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkpPrismaticConstraintData's destructor (slot 0 of its vtable): the
 * motor's reference given back. */
hkpPrismaticConstraintData::~hkpPrismaticConstraintData()
{
    if (atoms.motor.motor) {
        atoms.motor.motor->removeReference();
    }
}

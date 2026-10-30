/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkpRagdollConstraintData::~hkpRagdollConstraintData()
{
    for (int i = 0; i < 3; i++) {
        if (atoms.ragdollMotors.motors[i]) {
            atoms.ragdollMotors.motors[i]->removeReference();
        }
    }
}

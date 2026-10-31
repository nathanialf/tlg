/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The class's key function: its vtable is emitted here, the deleting
 * destructor (0x17b700) before the destructor (0x17b750). */
hkp6DofConstraintData::~hkp6DofConstraintData()
{
    for (int i = 0; i < 3; i++) {
        if (blueprints.ragdollMotors.motors[i]) {
            blueprints.ragdollMotors.motors[i]->removeReference();
        }
    }
}

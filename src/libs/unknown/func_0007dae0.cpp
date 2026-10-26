/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The motors' offsets into the runtime: its initialized flag at 144 and the
 * previous target angles at 148, set only when finishing. */
hkpRagdollConstraintData::Atoms::Atoms(hkFinishLoadedObjectFlag flag) : ragdollMotors(flag)
{
    if (flag.finishing) {
        ragdollMotors.initializedOffset = 144;
        ragdollMotors.previousTargetAnglesOffset = 148;
    }
}

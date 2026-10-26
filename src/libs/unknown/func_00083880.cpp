/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The motor's offsets into the runtime: its initialized flag at 112 and the
 * previous target position at 116, set only when finishing. */
hkpLinearClearanceConstraintData::Atoms::Atoms(hkFinishLoadedObjectFlag flag) : motor(flag)
{
    if (flag.finishing) {
        motor.initializedOffset = 112;
        motor.previousTargetPositionOffset = 116;
    }
}

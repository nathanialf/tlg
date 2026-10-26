/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The motor's offsets into the runtime: its initialized flag at 80 and the
 * previous target position at 84, set only when finishing. */
hkpPrismaticConstraintData::Atoms::Atoms(hkFinishLoadedObjectFlag flag) : motor(flag)
{
    if (flag.finishing) {
        motor.initializedOffset = 80;
        motor.previousTargetPositionOffset = 84;
    }
}

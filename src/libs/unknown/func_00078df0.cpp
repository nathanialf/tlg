/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The motor's offsets into the runtime: its initialized flag at 80, the
 * previous target angle at 84 and the angular limit's solver result at 32,
 * set only when finishing. */
hkpLimitedHingeConstraintData::Atoms::Atoms(hkFinishLoadedObjectFlag flag) : angMotor(flag)
{
    if (flag.finishing) {
        angMotor.initializedOffset = 80;
        angMotor.previousTargetAngleOffset = 84;
        angMotor.correspondingAngLimitSolverResultOffset = 32;
    }
}

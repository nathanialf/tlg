/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void CommandPrinter00171040::FUN_00171040(const hknpCommand &command,
                                          hkOstream &out) const /* derived name */
{
    switch (command.secondaryType) {
    case 0: {
        const CellIndexModifiedCommand &c = static_cast<const CellIndexModifiedCommand &>(command);
        out.FUN_00008440("CellIndexModifiedCommand Id=")
            .FUN_00008550(c.id)
            .FUN_00008440(" MotionIndex=")
            .FUN_00008550(c.motionIndex)
            .FUN_00008440(" OldCellIndex=")
            .FUN_000084c0(c.oldCellIndex)
            .FUN_00008440(" NewCellIndex=")
            .FUN_000084c0(c.newCellIndex);
        break;
    }
    case 1: {
        const hknpAtomSolverForceClippedCommand &c =
            static_cast<const hknpAtomSolverForceClippedCommand &>(command);
        out.FUN_00008440("hknpAtomSolverForceClippedCommand factor=").FUN_00008600(c.factor);
        break;
    }
    case 2: {
        const hknpValidateTriggerEventCommand &c =
            static_cast<const hknpValidateTriggerEventCommand &>(command);
        out.FUN_00008440("hknpValidateTriggerEventCommand id[0]=")
            .FUN_00008550(c.id0)
            .FUN_00008440(" id[1]=")
            .FUN_00008550(c.id1);
        break;
    }
    case 3:
        static_cast<const hknpMotionWeldTOICommand &>(command).FUN_00170f20(world, out);
        break;
    case 4: {
        const hknpAddContactConstraintRangeCommand &c =
            static_cast<const hknpAddContactConstraintRangeCommand &>(command);
        out.FUN_00008440("hknpAddContactConstraintRangeCommand idA=").FUN_00008550(c.idA);
        break;
    }
    }
}

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpMotionWeldTOICommand::FUN_00170f20(const hknpWorld *world,
                                            hkOstream &out) const /* derived name */
{
    Output0002b3b0 output;
    FUN_0003d7d0(world, &output);
    out.FUN_00008440("hknpMotionWeldTOICommand bodyIds=")
        .FUN_00008550(bodyIdA)
        .FUN_00008440(",")
        .FUN_00008550(bodyIdB)
        .FUN_00008440(" normal=")
        .FUN_000086b0(output.vector10)
        .FUN_00008440(" pos0=")
        .FUN_000086b0(output.vectors[0])
        .FUN_00008440(" pos1=")
        .FUN_000086b0(output.vectors[1])
        .FUN_00008440(" pos2=")
        .FUN_000086b0(output.vectors[2])
        .FUN_00008440(" pos3=")
        .FUN_000086b0(output.vectors[3]);
}

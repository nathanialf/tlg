/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the event, named by its status's lowest bit, its bodies'
 * ids and the normal, then each point's position and distance. */
void hknpManifoldEvent::FUN_00040a20(hknpWorld *world, hkOstream &out) const
{
    out.FUN_00008440("hknpManifoldEvent ")
        .FUN_00008440(D_1697760[countTrailingZeros(status)])
        .FUN_00008440(" bodyIds=")
        .FUN_00008550(bodyIdA)
        .FUN_00008440(",")
        .FUN_00008550(bodyIdB)
        .FUN_00008440(" normal=")
        .FUN_000086b0(normal);
    for (int i = 0; i < numPoints; i++) {
        out.FUN_00008440("\n\t\tpos=")
            .FUN_000086b0(positions[i])
            .FUN_00008440(" dist=")
            .FUN_00008600(distances[i]);
    }
}

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpBodyExitedBroadPhaseEvent::FUN_00155490(hknpWorld *world,
                                                 hkOstream &out) const /* derived name */
{
    out.FUN_00008440("BodyExitedBroadPhaseEvent id=").FUN_00008550(bodyId);
}

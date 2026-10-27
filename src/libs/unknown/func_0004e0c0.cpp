/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: a body in the broad phase is handed to the world's object
 * at +0x4f8; one outside it is left alone. */
void hknpWorld::FUN_0004e0c0(int bodyId)
{
    if (bodyManager.bodies[bodyId].broadPhaseId != static_cast<u32>(-1)) {
        object4f8->FUN_000639b0(bodyId);
    }
}

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void CollideSharedData::FUN_00167c20(const hknpWorld *world)
{
    solverInfo = &world->solverInfo;
    vector20 = world->vector250;
    pointer8 = world->spaceSplitter;
    object40 = world->unknown1f0;
    object0 = world->enabled278 ? world->unknown280 : 0;
    bodies = world->bodyManager.bodies.data;
    motions = world->motionManager.motions.data;
    int68 = -1;
    int6c = 0;
}

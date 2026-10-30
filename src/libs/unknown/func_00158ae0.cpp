/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpVehicleRayCastWheelCollide::FUN_00158ae0(const hknpVehicleInstance::WheelInfo &wheelInfo,
                                                  const hknpWorld *world,
                                                  hknpCollisionQueryCollector *collector) const
{
    hknpRayCastQuery query(wheelInfo.hardPointWs, wheelInfo.rayEndPointWs);
    query.filterData.collisionFilterInfo = wheelCollisionFilterInfo;
    query.filter = world->modifierManager->collisionFilter.pntr;
    world->FUN_00035d40(&query, collector);
}

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The wheel's shape cast in the world from its state's position to its
 * cast's end, the chassis's body the query's and the wheel collide's filter
 * info, the closest hit kept: copied out when there is one. */
/* NONMATCHING: 726 bytes against 720, equal but for the hit's copy: its two
 * 16-byte runs (shape key, filter info, user data) are copied from frame
 * addresses in the base, from two lea'd pointers here: the memcpy's source
 * is the entry block's address of the kept hit's key that the collector's
 * constructor stores through (EarlyCSE/GVN reuse it across blocks, and
 * CodeGenPrepare sinks addresses only into loads and stores, not into a
 * memcpy's operands). Which source keeps the copy's address its own is
 * the question. NOTES Round 81A. */
hkBool hknpVehicleLinearCastWheelCollide::FUN_00179210(const hknpVehicleInstance *vehicle,
                                                       u8 wheelIndex, const hknpWorld *world,
                                                       hknpCollisionResult &result) const
{
    const WheelState &wheelState = wheelStates[wheelIndex];
    hknpClosestHitCollector collector;
    hknpShapeCastQuery query(*wheelState.shape, wheelState.transform.translation, wheelState.to);
    query.filter = world->modifierManager->collisionFilter.pntr;
    query.filterData.collisionFilterInfo = wheelCollisionFilterInfo;
    query.body = &world->bodyManager.bodies[chassisBody];
    world->FUN_00035de0(&query, &wheelState.transform, &collector, HK_NULL);
    if (collector.hasHit) {
        result = collector.hit;
        return true;
    }
    return false;
}

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

int hknpVehicleInstance::FUN_001653b0(float deltaTime, const hknpWorld *world)
{
    /* The chassis gone from the world: the action is done with. */
    const int chassisId = bodyId.value;
    if (chassisId == 0x7fffffff) {
        return 1;
    }
    if (u32(world->bodyManager.bodies.getCapacity()) <= u32(chassisId)) {
        return 1;
    }
    const hknpBody &chassis = world->bodyManager.bodies.data[chassisId];
    if (!(chassis.flags & 3)) {
        return 1;
    }
    if (chassis.broadPhaseId == 0xffffffff || !(chassis.flags & hknpBody::IS_ACTIVE)) {
        return 0;
    }

    FUN_00162e10();

    const int numWheels = data->numWheels;
    WheelCollideOutput *collideOutputs =
        numWheels ? static_cast<WheelCollideOutput *>(
                        stackBlockAlloc(numWheels * int(sizeof(WheelCollideOutput))))
                  : 0;
    wheelCollide->collideWheels(deltaTime, this, collideOutputs, this->world);

    hknpVehicleJobResults vehicleResults;
    FUN_00165210(deltaTime, collideOutputs, vehicleResults);

    D_16dc078->timerBegin("TtApplyVehicleForces");
    hknpMotion &motion =
        this->world->motionManager.motions[this->world->bodyManager.bodies[bodyId.value].motionId];
    motion.FUN_00157630(vehicleResults.chassisAngularVelocity);
    motion.linearVelocity = vehicleResults.chassisLinearVelocity;
    D_16dc078->timerEnd("Et");

    stackBlockFree(collideOutputs, LocalBuffer<WheelCollideOutput>::roundedSize(numWheels));
    return 0;
}

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpVehicleInstance::FUN_00162e10()
{
    D_16dc078->timerBegin("TtUpdateBeforeCD");
    const hkTransform &chassisTransform = world->bodyManager.bodies[bodyId.value].transform;
    for (int w = 0; w < data->numWheels; w++) {
        WheelInfo &wheelInfo = wheelsInfo[w];
        FUN_00010ef0(wheelInfo.suspensionDirectionWs, chassisTransform.rotation,
                     suspension->wheelParams[w].directionChassisSpace.quad);
        FUN_00010f50(wheelInfo.hardPointWs, chassisTransform,
                     suspension->wheelParams[w].hardpointChassisSpace.quad);
        const float suspensionLength =
            suspension->wheelParams[w].length + data->wheelParams[w].radius;
        wheelInfo.rayEndPointWs =
            _mm_add_ps(_mm_mul_ps(_mm_set1_ps(suspensionLength), wheelInfo.suspensionDirectionWs),
                       wheelInfo.hardPointWs);
    }
    wheelCollide->updateBeforeCollisionDetection(this);
    D_16dc078->timerEnd("Et");
}

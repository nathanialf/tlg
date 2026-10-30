/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The chassis body's linear speed in kilometres an hour. */
float hknpVehicleInstance::FUN_00165890() const /* derived name */
{
    const hknpMotion &motion =
        world->motionManager.motions[world->bodyManager.bodies[bodyId.value].motionId];
    const float speed = _mm_cvtss_f32(length3(motion.linearVelocity));
    // Kilometres per metre times seconds per hour, one factor.
    return speed * (0.001f * 3600.0f);
}

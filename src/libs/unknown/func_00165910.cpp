/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The chassis body's linear speed in miles an hour. */
float hknpVehicleInstance::FUN_00165910() const /* derived name */
{
    const hknpMotion &motion = world->motions[world->bodyManager.bodies[bodyId.value].motionId];
    const float speed = _mm_cvtss_f32(length3(motion.linearVelocity));
    // Seconds per hour over metres per mile, one factor.
    return speed * (3600.0f / 1609.3f);
}

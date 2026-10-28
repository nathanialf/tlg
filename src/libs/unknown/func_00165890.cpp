/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The chassis body's linear speed in kilometres an hour. */
// NONMATCHING: the base multiplies the length once by a constant that is
// the float product of the divisor's reciprocal and 3600 (0x14ca400:
// 0x40666667 for kilometres, 0x14ca404: 0x400f2af7 for miles), the fold of
// `speed / 1000.0f * 3600.0f` under reciprocal and reassociation math; the
// fixed line divides, then multiplies (docs/NOTES.md Round 46).
float hknpVehicleInstance::FUN_00165890() const /* derived name */
{
    const hknpMotion &motion = world->motions[world->bodyManager.bodies[bodyId.value].motionId];
    const float speed = _mm_cvtss_f32(length3(motion.linearVelocity));
    return speed / 1000.0f * 3600.0f;
}

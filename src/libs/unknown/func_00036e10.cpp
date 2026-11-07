/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpMotionPropertiesLibrary::FUN_00036e10(const hknpWorld *world)
{
    entries.elements.clear();
    const float unitScale = world->solverInfo.unitScale;
    const float gravity = _mm_cvtss_f32(length3(world->gravity));
    for (int preset = hknpMotionProperties::STATIC; preset <= hknpMotionProperties::DEBRIS;
         preset++) {
        hknpMotionProperties properties;
        properties.FUN_000396b0(hknpMotionProperties::Preset(preset), gravity, unitScale);
        properties.isExclusive = 1;
        FUN_00037030(properties);
    }
}

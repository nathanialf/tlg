/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: hknpMaterial's automatic flags recomputed from its values;
 * the mass changer's flag also stays when the user set it. */
void hknpMaterial::FUN_0006c740()
{
    u32 autoFlags = 0;
    if (restitution.value & 0x7fff) {
        autoFlags |= ENABLE_RESTITUTION;
    }
    if (triggerType != 0) {
        autoFlags |= ENABLE_TRIGGER;
    }
    if (maxContactImpulse != HK_REAL_MAX) {
        autoFlags |= ENABLE_IMPULSE_CLIPPING;
    }
    if (massChangerCategory == MASS_CHANGER_HEAVY || (flags & ENABLE_MASS_CHANGER)) {
        autoFlags |= ENABLE_MASS_CHANGER;
    }
    if (softContactForceFactor.getReal() != 0.0f) {
        autoFlags |= ENABLE_SOFT_CONTACTS;
    }
    if (surfaceVelocity) {
        autoFlags |= ENABLE_SURFACE_VELOCITY;
    }
    flags = (flags & ~u32(AUTO_FLAGS_MASK)) | (autoFlags & AUTO_FLAGS_MASK);
}

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The default material: everything zeroed, then no trigger, an even
 * friction of one half combined by the smaller and a restitution combined
 * by the larger, no impulse limit, a welding tolerance of 5 cm, the mass
 * changer off and collisions between dynamic convex objects disabled
 * within 5. */
hknpMaterial::hknpMaterial()
{
    FUN_0000e3d0(&name);
    FUN_00018160(this, 0, sizeof(hknpMaterial));
    triggerType = TRIGGER_TYPE_NONE;
    triggerManifoldTolerance = HK_REAL_MAX;
    dynamicFriction.setReal(0.5f);
    staticFriction.setReal(0.5f);
    frictionCombinePolicy = COMBINE_MIN;
    restitutionCombinePolicy = COMBINE_MAX;
    maxContactImpulse = HK_REAL_MAX;
    fractionOfClippedImpulseToApply = 1.0f;
    weldingTolerance.setReal(0.05f);
    massChangerCategory = MASS_CHANGER_IGNORE;
    massChangerHeavyObjectFactor.setReal(1.0f);
    disablingCollisionsBetweenCvxCvxDynamicObjectsDistance.setReal(5.0f);
}

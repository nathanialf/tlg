/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 7 of hknpProjectileGun's vtable (address point 0x16a4b40): the
 * reload time left counts down by the step while the gun has not
 * reloaded (the test fireGun makes, negated: a NaN counts down), and the
 * projectiles are stepped. */
void hknpProjectileGun::stepGun(float timeStep, hknpWorld *world, const void *characterBody,
                                const hkTransform &viewTransform, bool fire, bool fireRmb)
{
    if (!(reload <= 0.0f)) {
        reload -= timeStep;
    }
    updateProjectiles(timeStep, world, characterBody, viewTransform, fire, fireRmb);
}

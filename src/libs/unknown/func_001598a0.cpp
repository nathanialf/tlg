/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: hknpProjectileGun's slot 6: once the reload has run out,
 * starts it again and fires. */
void hknpProjectileGun::fireGun(hknpWorld *world, const hkTransform &viewTransform)
{
    if (reload <= 0.0f) {
        reload = reloadTime;
        onGunFired(world, viewTransform);
    }
}

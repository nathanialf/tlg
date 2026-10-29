/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hknpProjectileGun::reset(hknpWorld *world)
{
    const int numProjectiles = projectiles.size;
    for (int i = 0; i < numProjectiles; i++) {
        hknpGunProjectile *projectile = projectiles[i];
        projectile->destroy(npWorld);
        projectile->removeReference();
    }
    projectiles.clear();
}

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Each live projectile aged by the step and updated in the gun's world,
 * every projectile's touched flag cleared, then the destroyed ones
 * released and taken out, the last one moved into each one's place. */
void hknpProjectileGun::updateProjectiles(float timeStep, hknpWorld *world,
                                          const void *characterBody,
                                          const hkTransform &viewTransform, bool fire, bool fireRmb)
{
    const int numProjectiles = projectiles.size;
    for (int i = 0; i < numProjectiles; i++) {
        hknpGunProjectile *projectile = projectiles[i];
        if (!(projectile->flags & hknpGunProjectile::FLAG_DESTROYED)) {
            projectile->step(npWorld, timeStep);
        }
    }
    const int numToClear = projectiles.size;
    for (int i = 0; i < numToClear; i++) {
        projectiles[i]->flags &= ~hknpGunProjectile::FLAG_TOUCHED;
    }
    int numLeft = projectiles.size;
    for (int i = 0; i < numLeft; i++) {
        hknpGunProjectile *projectile = projectiles[i];
        if (projectile->flags & hknpGunProjectile::FLAG_DESTROYED) {
            projectile->removeReference();
            projectiles.removeAt(i);
            numLeft--;
            i--;
        }
    }
}

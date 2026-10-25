/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 8 of hknpFirstPersonGun's vtable (address point
 * 0x16a47f0), kept by hknpBallGun, hknpProjectileGun and hknpMountedBallGun
 * (0x16a48e0, 0x16a4b40, 0x16a5290): resets the gun in the given world
 * through slot 10. */
void hknpFirstPersonGun::FUN_00156870(hknpWorld *world) /* derived name */
{
    reset(world);
}

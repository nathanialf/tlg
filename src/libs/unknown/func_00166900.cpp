/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The ball gun's finish constructor, then the mounted gun's own type when
 * the object is being finished. */
hknpMountedBallGun::hknpMountedBallGun(hkFinishLoadedObjectFlag flag) : hknpBallGun(flag)
{
    if (flag.finishing) {
        type = WEAPON_TYPE_MOUNTEDBALLGUN;
    }
}

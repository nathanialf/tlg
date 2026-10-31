/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hknpBallGun's finish constructor: no bullet shape yet; when finishing,
 * its weapon type and a queue for the bullets' bodies, room for the most it
 * keeps in the world. */
hknpBallGun::hknpBallGun(hkFinishLoadedObjectFlag flag) : hknpFirstPersonGun(flag)
{
    if (flag.finishing) {
        type = WEAPON_TYPE_BALLGUN;
        addedBodyIds = new hkQueue<hknpBodyId>();
        addedBodyIds->setCapacity(maxBulletsInWorld);
    }
}

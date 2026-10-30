/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpBallGun::reset(hknpWorld *world)
{
    while (addedBodyIds->elementsInUse) {
        hknpBodyId bodyId;
        addedBodyIds->dequeue(bodyId);
        for (int i = listeners.getSize() - 1; i >= 0; i--) {
            listeners[i]->bulletRemovedCallback(bodyId, world);
        }
        world->FUN_0004e5d0(&bodyId, 1, 0);
    }
}

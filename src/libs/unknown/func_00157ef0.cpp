/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hknpBallGun::~hknpBallGun()
{
    while (addedBodyIds->getSize()) {
        hknpBodyId bodyId;
        addedBodyIds->dequeue(bodyId);
        for (int i = listeners.getSize() - 1; i >= 0; i--) {
            listeners[i]->bulletRemovedCallback(bodyId, HK_NULL);
        }
    }
    delete addedBodyIds;
}

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpWorld::FUN_0005b490(int firstBodyId, void *argument)
{
    const hknpBodyQualityLibrary *qualities = qualityLibrary;
    int bodyId = firstBodyId;
    do {
        hknpBody &body = bodyManager.bodies[bodyId];
        FUN_000cd040(&body, argument, &qualities->qualities[body.qualityId], &vector250,
                     &solverInfo, unknown1f0);
        bodyId = body.nextAttachedBodyId;
    } while (bodyId != firstBodyId);
}

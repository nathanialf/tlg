/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpBodyManager::FUN_00161400() /* derived name */
{
    hknpBody *bodyArray = bodies.data;
    hkAabb16 *aabbs = previousAabbs;
    const int numChanges = scheduledBodyChanges.size;
    for (int i = 0; i < numChanges; i++) {
        const ScheduledBodyChange &change = scheduledBodyChanges.data[i];
        if ((change.flags & 4) && change.bodyId < bodies.size) {
            hknpBody &body = bodyArray[change.bodyId];
            if ((body.flags & 3) && (body.flags & 1)) {
                aabbs[change.bodyId] = body.aabb;
                body.flags &= ~0x3c00;
                body.word74 = 0;
                body.byte73 = 0;
            }
        }
    }
}

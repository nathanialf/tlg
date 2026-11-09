/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void ShapeWatcherOwner::FUN_001562a0(hknpWorld *world)
{
    if (!anyShapeChanged) {
        return;
    }
    for (int i = watchers.getSize() - 1; i >= 0; i--) {
        ShapeWatcher *watcher = watchers[i];
        if (!watcher->shape) {
            watchers.removeAt(i);
            otherWatchers.pushBack(watcher);
        } else if (watcher->changeFlags.get()) {
            const int numBodies = watcher->bodyIds.getSize();
            for (int j = 0; j < numBodies; j++) {
                const int bodyId = watcher->bodyIds[j];
                hknpBody &body = world->bodyManager.bodies[bodyId];
                if (watcher->changeFlags.get(1)) {
                    if (!(body.flags & hknpBody::IS_DYNAMIC)) {
                        world->FUN_0005c900(bodyId, HK_NULL, 1, 0);
                    } else {
                        hknpMotion &motion = world->motionManager.motions[body.motionId];
                        body.FUN_0003a820(motion.centerOfMass);
                        world->FUN_0005b490(bodyId, &motion);
                    }
                    body.flags |= 0x1000;
                }
                if (body.broadPhaseId != 0xffffffff) {
                    if (watcher->changeFlags.get(4)) {
                        world->FUN_0005bf80(bodyId);
                    } else if (watcher->changeFlags.get(2)) {
                        world->FUN_0005fab0(bodyId);
                    } else {
                        if (!(body.flags & (hknpBody::IS_STATIC | hknpBody::IS_ACTIVE))) {
                            world->FUN_0004e0c0(bodyId);
                        }
                        if (body.flags & hknpBody::IS_STATIC) {
                            world->FUN_0004e0f0(&body.aabb);
                        }
                    }
                }
            }
            hkRefPtr<const hknpShape> shape = watcher->shape;
            world->signals.shapeChangedSignal.fire(world, shape, watcher->changeFlags.get(),
                                                   watcher->bodyIds.begin(),
                                                   watcher->bodyIds.getSize());
            watcher->changeFlags.clear();
        }
    }
    anyShapeChanged = false;
}

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: an entry's group activated: each of its dynamic bodies in
 * the active list that is not active yet activated (0x63da0), its motion's
 * centre gathered into a box and its count summed, the others that name a
 * body taken out of the list; the bodies spread by a splitter of kind 1;
 * the entry's head recorded; its pairs the world's filter keeps recorded as
 * the bodies' keys; its callbacks told from the last; then the entry taken
 * (0x622d0). */
void hknpWorldObject4f8::FUN_00063a40(int id)
{
    Entry18 *entry = unknown18[id];
    hkAabb aabb;
    aabb.setEmpty();
    activatedBodies.reserve(activatedBodies.getSize() + entry->bodyIds.getSize());
    int numBodies = 0;
    const int numBodyIds = entry->bodyIds.getSize();
    for (int i = 0; i < numBodyIds; i++) {
        const int bodyId = entry->bodyIds[i];
        hknpBody &body = world->bodyManager.bodies[bodyId];
        if (body.indexIntoActiveListOrDeactivatedIslandId != 0x7fffffff &&
            (body.flags & hknpBody::IS_DYNAMIC)) {
            if (!(body.flags & hknpBody::IS_ACTIVE)) {
                FUN_00063da0(bodyId);
                const hknpMotion &motion = world->motionManager.motions[body.motionId];
                aabb.includePoint(motion.centerOfMass);
                numBodies += motion.unknown3f;
            }
        } else if (world->isBodyValid(bodyId)) {
            body.indexIntoActiveListOrDeactivatedIslandId = 0x7fffffff;
        }
    }
    hknpSpaceSplitter *splitter = world->spaceSplitter;
    if (splitter->type == 1) {
        static_cast<FlaggedPoints00060c70 *>(splitter)->FUN_000611a0(numBodies, aabb);
    }
    activatedRanges.pushBack(entry->head);
    int numPairs = entry->bodyPairs.getSize();
    if (numPairs) {
        hknpCollisionFilter *filter = world->modifierManager->collisionFilter.pntr;
        if (filter) {
            numPairs = filter->FUN_001679a0(*world, entry->bodyPairs.data, numPairs);
        }
        BodyKeyPair0005c120 *keys = activatedPairs.expandBy(numPairs);
        for (int i = 0; i < numPairs; i++) {
            keys[i].bodyA =
                BodyKey0005c120(world->bodyManager.bodies[entry->bodyPairs[i].bodyIdA.value]);
            keys[i].bodyB =
                BodyKey0005c120(world->bodyManager.bodies[entry->bodyPairs[i].bodyIdB.value]);
        }
    }
    for (int i = entry->unknown30.getSize() - 1; i >= 0; i--) {
        entry->unknown30[i].object->unknownVirtual2(entry, entry->unknown30[i].data);
    }
    FUN_000622d0(id);
}

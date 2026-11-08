/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the caches the record spans walked; each still of a type
 * whose two bodies are not both in the broad phase with a motion, or which
 * are triggers (flag 0x400) or both static, handed to its type's detector
 * with the reason (2, 6 for a trigger, 8 for two static bodies), each body
 * as its body, motion, shape and material, then made of no type. */
void FUN_00065910(hknpWorldContextPool::Context *context, const ModifierSharedData *shared,
                  SortRecord00062100 *record, hkBlockStream *stream)
{
    hknpWorld *world = context->world;
    /* On a 16-byte boundary (Havok's HK_ALIGN16 on the local: the base's
     * reader sits at -0x50 with eight bytes to the guard, where the
     * readers of 0x155850, 0x15b7a0 and 0x317b0 sit at -0x48). */
    hkBlockStreamReader reader __attribute__((aligned(16)));
    reader.FUN_000937f0(record);
    for (hknpCollisionCache *cache =
             static_cast<hknpCollisionCache *>(const_cast<void *>(reader.access()));
         cache; cache = static_cast<hknpCollisionCache *>(
                    const_cast<void *>(reader.advanceToNext(cache->sizeInQuads * 16)))) {
        if (cache->type == 0) {
            continue;
        }
        const hknpBody &bodyA = world->bodyManager.bodies.data[int(cache->key0)];
        const hknpBody &bodyB = world->bodyManager.bodies.data[int(cache->key4)];
        int reason;
        bool collide;
        if ((bodyA.flags & 3) && bodyA.broadPhaseId != 0xffffffff && (bodyB.flags & 3) &&
            bodyB.broadPhaseId != 0xffffffff) {
            collide = false;
            reason = 0;
        } else {
            collide = true;
            reason = 2;
        }
        if ((bodyA.flags | bodyB.flags) & 0x400) {
            reason = 6;
            collide = true;
        }
        if ((bodyA.flags & 1) && (bodyB.flags & 1)) {
            reason = 8;
            collide = true;
        }
        if (!collide) {
            continue;
        }
        const hknpMotion *motions = world->motionManager.motions.data;
        hknpCdBody cdBodyA;
        cdBodyA.body = &bodyA;
        cdBodyA.leafShape = bodyA.shape;
        cdBodyA.motion =
            u32(bodyA.motionId) != 0x7fffffff ? &motions[u32(bodyA.motionId)] : HK_NULL;
        cdBodyA.material = &context->materials[bodyA.materialId.value];
        cdBodyA.shapeKey = 0xffffffff;
        hknpCdBody cdBodyB;
        cdBodyB.body = &bodyB;
        cdBodyB.leafShape = bodyB.shape;
        cdBodyB.motion =
            u32(bodyB.motionId) != 0x7fffffff ? &motions[u32(bodyB.motionId)] : HK_NULL;
        cdBodyB.material = &context->materials[bodyB.materialId.value];
        cdBodyB.shapeKey = 0xffffffff;
        context->modifierManager->collisionDetectors[cache->type]->unknownVirtual3(
            context, shared, cache, stream, stream, &cdBodyA, &cdBodyB, reason);
        cache->type = 0;
    }
}

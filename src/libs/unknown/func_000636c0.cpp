/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 151 of 155, size equal: one list-ilp order in the drop arm's first block: the
// base loads the context's world (`mov r14, [r15+8]`) before the pairs array's pointer from
// the stack argument, here after it and the capacity's mask; the IR holds the world's load
// first. NOTES Round 79A.
void FUN_000636c0(hknpWorldContextPool::Context *context, const ModifierSharedData *shared,
                  bool drop, const hknpCollisionCache *cache, hkBlockStream *childCacheStream,
                  hkBlockStreamWriter *writer, hkBlockStreamWriter *childCacheWriter,
                  hkArray<hknpBodyIdPair> *droppedPairs)
{
    if (drop) {
        const hknpWorld *world = context->world;
        hknpBodyIdPair &pair = droppedPairs->expandOne();
        pair.bodyIdA.value = cache->key0;
        pair.bodyIdB.value = cache->key4;
        const hknpBody &bodyA = world->bodyManager.bodies.data[int(cache->key0)];
        const hknpBody &bodyB = world->bodyManager.bodies.data[int(cache->key4)];
        const hknpMotion *motions = context->world->motionManager.motions.data;
        hknpCdBody cdBodyA;
        cdBodyA.body = &bodyA;
        cdBodyA.leafShape = bodyA.shape;
        cdBodyA.motion = &motions[u32(bodyA.motionId)];
        cdBodyA.material = &context->materials[bodyA.materialId.value];
        cdBodyA.shapeKey = 0xffffffff;
        hknpCdBody cdBodyB;
        cdBodyB.body = &bodyB;
        cdBodyB.leafShape = bodyB.shape;
        cdBodyB.motion = &motions[u32(bodyB.motionId)];
        cdBodyB.material = &context->materials[bodyB.materialId.value];
        cdBodyB.shapeKey = 0xffffffff;
        context->modifierManager->collisionDetectors[cache->type]->unknownVirtual3(
            context, shared, cache, childCacheStream, HK_NULL, &cdBodyA, &cdBodyB, 5);
        return;
    }
    hknpCollisionCache *copy =
        static_cast<hknpCollisionCache *>(writer->reserve(cache->sizeInQuads * 16));
    hkString::memCpy16NonEmpty(copy, cache, cache->sizeInQuads);
    hknpCollisionDetector *detector = context->modifierManager->collisionDetectors[copy->type];
    if (copy->type == 2 && copy->sizeInQuads >= 3) {
        reinterpret_cast<hknpManifoldCollisionCache *>(copy)->resetSolverRecord();
    }
    if (detector->hasChildCaches) {
        detector->moveChildCaches(context, copy, childCacheStream, HK_NULL, childCacheWriter);
    }
    writer->advance(copy->sizeInQuads * 16);
}

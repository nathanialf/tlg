/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpCompositeCollisionDetector::unknownVirtual3(
    hknpWorldContextPool::Context *context, const void *sharedData, const hknpCollisionCache *cache,
    hkBlockStream *childCacheStream, hkBlockStream *childCacheStreamPpu, hknpCdBody *cdBodyA,
    hknpCdBody *cdBodyB, int argument8)
{
    const hknpCompositeCollisionCache *compositeCache =
        static_cast<const hknpCompositeCollisionCache *>(cache);
    hkBlockStreamConsumer consumer;
    consumer.FUN_00093ab0(context->cache258, childCacheStream, childCacheStreamPpu,
                          &compositeCache->childCaches);
    for (const hknpCollisionCache *child =
             static_cast<const hknpCollisionCache *>(consumer.access());
         child; child = static_cast<const hknpCollisionCache *>(
                    consumer.consumeAndAdvance(child->sizeInQuads * 16))) {
        if (child->type == 2) {
            cdBodyB->shapeKey = child->key0;
        } else if (child->type == 3) {
            cdBodyA->shapeKey = child->key0;
        }
        context->modifierManager->collisionDetectors[child->type]->unknownVirtual3(
            context, sharedData, child, 0, 0, cdBodyA, cdBodyB, argument8);
    }
}

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpCompositeCollisionDetector::FUN_00155750(hknpWorldContextPool::Context *context,
                                                  const void *sharedData,
                                                  const hknpCompositeCollisionCache *cache,
                                                  void *argument4, void *argument5,
                                                  hknpCdBody *cdBodyA, hknpCdBody *cdBodyB,
                                                  int argument8)
{
    hkBlockStreamReader reader;
    reader.FUN_000937f0(&cache->childCaches);
    for (const hknpCollisionCache *child = static_cast<const hknpCollisionCache *>(reader.access());
         child;
         child = static_cast<const hknpCollisionCache *>(reader.advance(child->sizeInQuads * 16))) {
        if (child->type == 2) {
            cdBodyB->shapeKey = child->key0;
        } else if (child->type == 3) {
            cdBodyA->shapeKey = child->key0;
        }
        context->modifierManager->collisionDetectors[child->type]->collide(
            context, sharedData, child, argument4, argument5, cdBodyA, cdBodyB, argument8);
    }
}

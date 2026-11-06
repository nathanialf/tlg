/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpCompositeCollisionDetector::FUN_001555a0(hknpWorldContextPool::Context *context,
                                                  hknpCompositeCollisionCache *cache,
                                                  hkBlockStream *childCacheStream,
                                                  hkBlockStream *childCacheStreamPpu,
                                                  hkBlockStreamWriter *writer)
{
    hkBlockStreamConsumer consumer;
    consumer.FUN_00093ab0(context->cache258, childCacheStream, childCacheStreamPpu,
                          &cache->childCaches);
    cache->childCaches.setStartPoint(writer);
    for (const hknpCollisionCache *child =
             static_cast<const hknpCollisionCache *>(consumer.access());
         child; child = static_cast<const hknpCollisionCache *>(
                    consumer.consumeAndAdvance(child->sizeInQuads * 16))) {
        hknpCollisionCache *copy =
            static_cast<hknpCollisionCache *>(writer->reserve(child->sizeInQuads * 16));
        hkString::memCpy16NonEmpty(copy, child, child->sizeInQuads);
        if (copy->type == 2) {
            if (copy->sizeInQuads >= 3) {
                reinterpret_cast<hknpManifoldCollisionCache *>(copy)->resetSolverRecord();
            }
        } else if (copy->type == 3) {
            static_cast<hknpCompositeCollisionCache *>(copy)->resetChildState();
        }
        writer->advance(child->sizeInQuads * 16);
    }
    cache->childCaches.FUN_00092220(writer);
    cache->resetState();
}

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpCompositeCollisionDetector::FUN_00155850(const void *argument1,
                                                  hknpCompositeCollisionCache *cache,
                                                  hkBlockStreamWriter *writer)
{
    hkBlockStreamReader reader;
    reader.FUN_000937f0(&cache->childCaches);
    cache->childCaches.setStartPoint(writer);
    for (const hknpCollisionCache *child = static_cast<const hknpCollisionCache *>(reader.access());
         child;
         child = static_cast<const hknpCollisionCache *>(reader.advance(child->sizeInQuads * 16))) {
        const int numQuads = child->sizeInQuads;
        const int numBytes = numQuads * 16;
        void *copy = writer->reserve(numBytes);
        hkString::memCpy16NonEmpty(copy, child, numQuads);
        writer->advance(numBytes);
    }
    cache->childCaches.FUN_00092220(writer);
}

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The values, at most 502, as a cache of type 7 in the writer's stream: its
 * size in quads from the values after the first, the three 16-bit fields
 * cleared as one run of six bytes (the base's dword and word stores, which
 * three field stores followed by the counts' stores do not merge, cookbook
 * 273), the count stored twice, then the values copied; the cache returned
 * (its pointer stays in rax across the copy, cookbook 274). */
ValuesCache00176110 *FUN_00176110(const u32 *values, int numValues, hkBlockStreamWriter *writer)
{
    const u32 size = u32(hkMath::max2(0, hkMath::min2(numValues - 1, 501)) * 4 + 44);
    const int numBytes = int(size & ~15u);
    ValuesCache00176110 *cache = static_cast<ValuesCache00176110 *>(writer->reserve(numBytes));
    cache->header.type = 7;
    cache->header.sizeInQuads = u8(size >> 4);
    memset(&cache->unknownA, 0, 6);
    const int numCopied = hkMath::min2(numValues, 502);
    cache->numValues = cache->numValuesCopied = numCopied;
    for (int i = 0; i < numCopied; i++) {
        cache->values[i] = values[i];
    }
    writer->advance(numBytes);
    return cache;
}

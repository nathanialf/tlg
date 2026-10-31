/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

// NONMATCHING: the same blocks and operations, 315 bytes against 331, the
// registers apart: the key's bit for the in-use byte is computed in the base
// after the size test (`mov eax, 1; mov cl, sil; shl eax, cl` at 0x17a0f1),
// where here InstCombine's canonical test ((X >> Y) & 1 == 0 into
// X & (1 << Y), InstCombineCompares.cpp:1240-1260) puts the shift in the
// entry and GVN shares it with the store's, which then lives across both
// tests (docs/NOTES.md, Round 67A).

/* A property reserved under a key: placed at the properties' end (key 0's
 * nibble) aligned up, its offset recorded in its key's nibble; the cache
 * grown to hold the properties and the three point arrays after them, the
 * arrays moved up 16 bytes at a time from the last; the end advanced, and
 * the properties marked full at 64 bytes. Null when the key is taken or the
 * property does not fit. */
void *FUN_0017a0a0(hknpManifoldCollisionCache *cache, u8 propertyKey, u8 size,
                   int alignment) /* derived name */
{
    if ((cache->propertyKeysUsed >> propertyKey) & 1) {
        return HK_NULL;
    }
    const u32 offset = ((cache->propertyOffsets & 0xf) * 4 + alignment - 1) & -alignment;
    const int alignedSize = (size + 3) & ~3;
    const int bufferSize = (offset + alignedSize + 15) & ~15;
    if (bufferSize > 64) {
        return HK_NULL;
    }
    cache->propertyKeysUsed |= 1 << propertyKey;
    const int shift = propertyKey * 4;
    cache->propertyOffsets = (cache->propertyOffsets & ~(0xf << shift)) | ((offset >> 2) << shift);

    const int arraySize = ((cache->pointValueCount + 3) & ~3) * int(sizeof(float));
    const u32 totalSize = cache->propertyBufferOffset * 16 + bufferSize + 3 * arraySize;
    const u32 cacheSize = cache->sizeInQuads * 16;
    if (cacheSize < totalSize) {
        if (arraySize) {
            const Vec4 *from =
                hkAddByteOffset(reinterpret_cast<const Vec4 *>(cache),
                                cache->propertyBufferOffset * 16 + cache->propertyBufferSize());
            Vec4 *to = hkAddByteOffset(const_cast<Vec4 *>(from), totalSize - cacheSize);
            int i = 3 * arraySize / 16;
            do {
                i--;
                to[i] = from[i];
            } while (i > 0);
        }
        cache->sizeInQuads = u8(totalSize >> 4);
    }
    cache->propertyOffsets = (cache->propertyOffsets & ~0xfu) | ((alignedSize + offset) >> 2);
    if (bufferSize == 64) {
        cache->propertyKeysUsed |= 1;
    }
    return reinterpret_cast<char *>(cache) + (cache->propertyBufferOffset * 16 + offset);
}

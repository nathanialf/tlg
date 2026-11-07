/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include <smmintrin.h>

#include "tlg_lib_unknown.h"

/* The hash of a position: its x, y and z bits mixed by rotations, the
 * lowest bit cleared. derived name. */
static inline u32 hashPosition(const hkVector4 &position) /* derived name */
{
    const __m128i bits = _mm_castps_si128(position.quad);
    const u32 x = u32(_mm_cvtsi128_si32(bits));
    const u32 y = u32(_mm_extract_epi32(bits, 1));
    const u32 z = u32(_mm_extract_epi32(bits, 2));
    return (x ^ ((y << 16) | (y >> 16)) ^ ((z << 29) | (z >> 3))) & ~1u;
}

/* Whether two positions are equal in x, y and z: the lanes compared, then
 * the x, y and z lanes' results all set. derived name. */
static inline bool equalXyz(const hkVector4 &a, const hkVector4 &b) /* derived name */
{
    const __m128i equal = _mm_castps_si128(_mm_cmpeq_ps(a.quad, b.quad));
    const __m128i xyz =
        _mm_castps_si128(_mm_blend_ps(_mm_setzero_ps(), _mm_castsi128_ps(_mm_set1_epi32(-1)), 7));
    return _mm_testc_si128(_mm_and_si128(equal, xyz), xyz);
}

/* The chain of the position's hash walked for an equal position; a new
 * position starts a chain, or joins the hash's chain after its first
 * entry. */
int UniquePositions000aa8b0::FUN_000aa8b0(const hkVector4 &position)
{
    const u32 hash = hashPosition(position);
    const PointerMap::Iterator it = hashMap.FUN_00013ad0(hash);
    const int newIndex = positions.getSize();
    if (hashMap.isValid(it)) {
        const int firstEntryIndex = int(hashMap.getValue(it));
        const Entry *entry = &entries.data[firstEntryIndex];
        while (!equalXyz(positions.data[entry->positionIndex], position)) {
            if (entry->nextEntryIndex < 0) {
                positions.pushBack(position);
                const int newEntryIndex = entries.getSize();
                Entry &newEntry = entries.expandOne();
                Entry &firstEntry = entries.data[firstEntryIndex];
                newEntry.positionIndex = newIndex;
                newEntry.nextEntryIndex = firstEntry.nextEntryIndex;
                firstEntry.nextEntryIndex = newEntryIndex;
                return newIndex;
            }
            entry = &entries.data[entry->nextEntryIndex];
        }
        return entry->positionIndex;
    }

    positions.pushBack(position);
    const int entryIndex = entries.getSize();
    Entry &entry = entries.expandOne();
    entry.positionIndex = newIndex;
    entry.nextEntryIndex = -1;
    hashMap.insert(hash, entryIndex);
    return newIndex;
}

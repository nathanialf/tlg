/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 7 of 96, 337 bytes against 335; the blocks are the base's but
// for the clearing: the base allocates (or not, for no words), joins, then
// tests the count again and clears through a memset of 4 * (n + smax(-n, -1))
// + 4 bytes (the trip count of `i < n` with n opaque to SCEV); here
// JumpThreading threads the zero count past both and SCEV sizes the memset
// from (count + 31) / 32 (umax form), which moves every register
// (docs/NOTES.md, Round 67A).

/* The number of distinct vertex ids (the low half of each vertex's w), one
 * bit per id in a local array of words cleared first. derived name. */
int FUN_001707d0(const hknpConvexShape *shape)
{
    const u16 numVertices = shape->vertices.size;
    const Vec4 *vertices = reinterpret_cast<const Vec4 *>(
        reinterpret_cast<const char *>(&shape->vertices) + shape->vertices.offset);
    const int numWords = (numVertices + 31) >> 5;
    u32 *seen = numWords ? stackAllocate<u32>(numWords) : HK_NULL;
    for (int i = 0; i < numWords; i++) {
        seen[i] = 0;
    }
    int numIds = 0;
    for (int i = 0; i < numVertices; i++) {
        const int id = reinterpret_cast<const u16 *>(&vertices[i])[6];
        const u32 bit = 1u << (id & 31);
        u32 &word = seen[id >> 5];
        if (!(word & bit)) {
            word |= bit;
            numIds++;
        }
    }
    stackBlockFree(seen, LocalBuffer<u32>::roundedSize(numWords));
    return numIds;
}

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The number of distinct vertex ids (the low half of each vertex's w), one
 * bit per id in a local array of words sized and cleared first. derived
 * name. */
int FUN_001707d0(const hknpConvexShape *shape)
{
    const int numVertices = shape->vertices.size;
    const Vec4 *vertices = reinterpret_cast<const Vec4 *>(
        reinterpret_cast<const char *>(&shape->vertices) + shape->vertices.offset);
    const int numWords = (numVertices + 31) >> 5;
    LocalArray<u32> seen(numWords);
    seen.setSize(numWords);
    hkString::memSet4(seen.data, 0, seen.getSize());
    int numIds = 0;
    for (int i = 0; i < numVertices; i++) {
        const int id = reinterpret_cast<const u16 *>(&vertices[i])[6];
        if (!((seen[id >> 5] >> (id & 31)) & 1)) {
            seen[id >> 5] |= 1 << (id & 31);
            numIds++;
        }
    }
    return numIds;
}

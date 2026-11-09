/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The number of distinct vertex ids (the low half of each vertex's w), one
 * bit per id in a local bit field cleared first (Havok's hkLocalBitField,
 * as 0x372a0's; the words' array written out with its own setSize does not
 * fold the reserve under the SDK's member order, D41; round 105A). derived
 * name. */
int FUN_001707d0(const hknpConvexShape *shape)
{
    const int numVertices = shape->vertices.size;
    const Vec4 *vertices = reinterpret_cast<const Vec4 *>(
        reinterpret_cast<const char *>(&shape->vertices) + shape->vertices.offset);
    LocalBitField seen(numVertices, 0);
    int numIds = 0;
    for (int i = 0; i < numVertices; i++) {
        const int id = reinterpret_cast<const u16 *>(&vertices[i])[6];
        if (!seen.get(id)) {
            seen.set(id);
            numIds++;
        }
    }
    return numIds;
}

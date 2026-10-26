/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the size of a polytope shape: the class, then the vertices
 * and the face planes (a vector each), the faces (4 bytes each) and the
 * indices (a byte each), the class and the faces rounded up to 16 and the
 * total too. */
int hknpConvexPolytopeShape::FUN_001542f0(int numVertices, int numFaces, int numIndices,
                                          int sizeOfBaseClass)
{
    int size = (sizeOfBaseClass + 15) & ~15;
    size += numVertices * 16;
    size += numFaces * 16;
    size += (numFaces * 4 + 15) & ~15;
    size += numIndices;
    return (size + 15) & ~15;
}

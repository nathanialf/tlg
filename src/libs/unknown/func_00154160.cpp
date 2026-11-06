/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The masks, file-local (D17); the rows are written at build time from the
 * user's executable (D18, config/data_schema.base.txt). */
static const hknpConvexPolytopeShape::IndexMask D_14c9e50[32] = {
#include "gen/D_14c9e50.inc"
};

/* Each four vertices are read before they are written: the output may be
 * the shape's own memory. The face's indices are found from the array's
 * bytes, the first index added to the array's offset. */
// NONMATCHING: 82 of 90, one list-ilp choice: the vertices' start through beginBytes gives the
// base's `lea rbx, [r8 + rdi]` (round 72B's lea class, the DAG's add over the offset first); left:
// the first two index bytes' loads, the base loading index 0 early (r15) and index 1 just before
// its vertex (rdx), this compile the other way. Debug llc (-debug-only=pre-RA-sched): GR64 at
// 12/12, BURRSort picks the second mask byte (SU 37) at step 26 by height, then index 0, where
// the base must take index 1 and the vertices' lea first (NOTES "Round 73B").
int hknpConvexPolytopeShape::FUN_00154160(int faceIndex, Vec4 *planeOut, Vec4 *verticesOut) const
{
    const Face &face = faces.begin()[faceIndex];
    const int numIndices = face.numIndices;
    const u8 *faceIndices = &indices.beginBytes()[face.firstIndex];
    const Vec4 *faceVertices = vertices.beginBytes();
    *planeOut = planes.begin()[faceIndex];
    const IndexMask *masks = &D_14c9e50[16 - numIndices];

    const Vec4 v0 = faceVertices[faceIndices[0]];
    const Vec4 v1 = faceVertices[faceIndices[1]];
    const Vec4 v2 = faceVertices[faceIndices[2 & masks[2].value]];
    const Vec4 v3 = faceVertices[faceIndices[3 & masks[3].value]];
    verticesOut[0] = v0;
    verticesOut[1] = v1;
    verticesOut[2] = v2;
    verticesOut[3] = v3;
    for (int i = 4; i < numIndices; i += 4) {
        const Vec4 a = faceVertices[faceIndices[i]];
        const Vec4 b = faceVertices[faceIndices[(i + 1) & masks[i + 1].value]];
        const Vec4 c = faceVertices[faceIndices[(i + 2) & masks[i + 2].value]];
        const Vec4 d = faceVertices[faceIndices[(i + 3) & masks[i + 3].value]];
        verticesOut[i] = a;
        verticesOut[i + 1] = b;
        verticesOut[i + 2] = c;
        verticesOut[i + 3] = d;
    }
    return numIndices;
}

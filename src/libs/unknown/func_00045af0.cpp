/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

int hknpConvexShape::FUN_00045af0(int faceIndex, Vec4 *planeOut, Vec4 *verticesOut) const
{
    hknpFaceAngle angle;
    unknownVirtual14(faceIndex, planeOut, &angle);
    const Vec4 *faceVertices = vertices.begin(); /* derived name */
    const u32 indices = u32(faceIndex);          /* derived name */
    verticesOut[0] = faceVertices[indices >> 24];
    verticesOut[1] = faceVertices[(indices >> 16) & 0xff];
    verticesOut[2] = faceVertices[(indices >> 8) & 0xff];
    verticesOut[3] = faceVertices[indices & 0xff];
    return 4;
}

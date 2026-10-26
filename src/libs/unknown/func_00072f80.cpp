/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the face's plane, and its minimum half angle. */
void hknpConvexPolytopeShape::FUN_00072f80(int faceIndex, Vec4 &planeOut, u8 &minAngleOut) const
{
    planeOut = planes.begin()[faceIndex];
    minAngleOut = faces.begin()[faceIndex].minHalfAngle;
}

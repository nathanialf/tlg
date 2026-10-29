/* src/libs/havok/Physics/Physics/Collide/Shape/hknpShape.cpp:
 * the file its reports name (config/homes.base.txt, FUN_0006e470). */
#include "tlg_lib_unknown.h"

/* hknpShape's defaults that a shape type must override: each reports "Not
 * implemented" under its own id, at the line of the file the executable
 * gives. */

void hknpShape::unknownVirtual7(const Mat4 &transform, hkAabb &aabbOut) const
{
    HK_ERROR(0x7fe8e736, HK_NP_SHAPE_CPP, 38, "Not implemented");
}

void hknpShape::unknownVirtual11(const Vec4 &direction, Vec4 *vertexOut) const
{
    HK_ERROR(0x28d78a7d, HK_NP_SHAPE_CPP, 61, "Not implemented");
}

void hknpShape::unknownVirtual12(const u8 *ids, int numIds, Vec4 *verticesOut) const
{
    HK_ERROR(0x43342a57, HK_NP_SHAPE_CPP, 66, "Not implemented");
}

void hknpShape::unknownVirtual14(int faceIndex, Vec4 *planeOut, u8 *valueOut) const
{
    HK_ERROR(0x7d77da16, HK_NP_SHAPE_CPP, 83, "Not implemented");
}

void hknpShape::unknownVirtual18(const void *argument1, void *argument2) const
{
    HK_ERROR(0x168b0b4f, HK_NP_SHAPE_CPP, 102, "Not implemented");
}

void hknpShape::unknownVirtual22(const void *argument1, const void *argument2,
                                 void *argument3) const
{
    HK_ERROR(0x1d729a31, HK_NP_SHAPE_CPP, 129, "Not implemented");
}

void hknpShape::unknownVirtual25(const void *argument1, const void *argument2,
                                 const void *argument3, const void *argument4,
                                 void *argument5) const
{
    HK_ERROR(0x698a584c, HK_NP_SHAPE_CPP, 142, "Not implemented");
}

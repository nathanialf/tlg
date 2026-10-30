/* src/libs/havok/Physics/Physics/Collide/Shape/hknpShape.cpp:
 * the file its reports name (config/homes.base.txt, FUN_0006e470). */
#include "tlg_lib_unknown.h"

/* hknpShape's defaults that a shape type must override: each reports "Not
 * implemented" under its own id, at the line of the file the executable
 * gives. */

int hknpShape::unknownVirtual5() const
{
    HK_ERROR(0x4cc169fa, HK_NP_SHAPE_CPP, 32, "Not implemented");
    return 22;
}

void hknpShape::unknownVirtual7(const Mat4 &transform, hkAabb &aabbOut) const
{
    HK_ERROR(0x7fe8e736, HK_NP_SHAPE_CPP, 38, "Not implemented");
}

int hknpShape::unknownVirtual6() const
{
    HK_ERROR(0x2667021d, HK_NP_SHAPE_CPP, 43, "Not implemented");
    return 0;
}

int hknpShape::unknownVirtual9() const
{
    HK_ERROR(0x2c82390a, HK_NP_SHAPE_CPP, 49, "Not implemented");
    return 0;
}

const Vec4 *hknpShape::unknownVirtual10(Vec4 *buffer, int bufferSize) const
{
    HK_ERROR(0x6c22654c, HK_NP_SHAPE_CPP, 55, "Not implemented");
    return 0;
}

void hknpShape::unknownVirtual11(const Vec4 &direction, Vec4 *vertexOut) const
{
    HK_ERROR(0x28d78a7d, HK_NP_SHAPE_CPP, 61, "Not implemented");
}

void hknpShape::unknownVirtual12(const u8 *ids, int numIds, Vec4 *verticesOut) const
{
    HK_ERROR(0x43342a57, HK_NP_SHAPE_CPP, 66, "Not implemented");
}

int hknpShape::unknownVirtual13() const
{
    HK_ERROR(0x7205d788, HK_NP_SHAPE_CPP, 71, "Not implemented");
    return 0;
}

int hknpShape::unknownVirtual15(int faceIndex, Vec4 *planeOut, Vec4 *verticesOut) const
{
    HK_ERROR(0x480c7f47, HK_NP_SHAPE_CPP, 77, "Not implemented");
    return 0;
}

void hknpShape::unknownVirtual14(int faceIndex, Vec4 *planeOut, hknpFaceAngle *angleOut) const
{
    HK_ERROR(0x7d77da16, HK_NP_SHAPE_CPP, 83, "Not implemented");
}

int hknpShape::unknownVirtual16(const void *argument1, const void *argument2, void *argument3,
                                bool argument4, int argument5) const
{
    HK_ERROR(0x0a03840a, HK_NP_SHAPE_CPP, 90, "Not implemented");
    return 0;
}

float hknpShape::unknownVirtual17() const
{
    HK_ERROR(0x5d043200, HK_NP_SHAPE_CPP, 96, "Not implemented");
    return 0.0f;
}

void hknpShape::unknownVirtual18(const void *argument1, void *argument2) const
{
    HK_ERROR(0x168b0b4f, HK_NP_SHAPE_CPP, 102, "Not implemented");
}

int hknpShape::unknownVirtual21(void *argument1, int argument2, int argument3,
                                const ShapeKeyQuery000380b0 &argument4) const
{
    HK_ERROR(0xafb26ded, HK_NP_SHAPE_CPP, 123, "Not implemented");
    return argument2;
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

void hknpShape::unknownVirtual26(const void *argument1, const void *argument2,
                                 const void *argument3, const void *argument4,
                                 void *argument5) const
{
    HK_ERROR(0x249de87e, HK_NP_SHAPE_CPP, 150, "Not implemented");
}

void hknpShape::unknownVirtual23(const void *argument1, const void *argument2,
                                 const void *argument3, const void *argument4,
                                 void *argument5) const
{
    HK_ERROR(0x7ba2ada7, HK_NP_SHAPE_CPP, 158, "Not implemented");
}

hknpShapeKeyMask *hknpShape::unknownVirtual20() const
{
    HK_ERROR(0xc26a7711, HK_NP_SHAPE_CPP, 203, "Not implemented");
    return 0;
}

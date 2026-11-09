/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* An int in every lane, converted through a double (`vcvtsi2sd; vmovq;
 * vcvtpd2ps`, 0x178830). derived name. */
static inline Vec4 simdFromInt(int i)
{
    const Vec4 x = _mm_cvtpd_ps(_mm_cvtsi32_sd(_mm_setzero_pd(), i));
    return _mm_shuffle_ps(x, x, _MM_SHUFFLE(0, 0, 0, 0));
}

/* The wheel as a cylinder of 32 sides: its two rims a quarter of the width
 * either side of the centre along z, each side's point the radius out along
 * a direction perpendicular to the axis, turned about it. */
// NONMATCHING: the frame and list-ilp order around the allocation, 886 bytes against 882 (frame
// 0x138 as the base): stack coloring gives the allocation's byte count (allocateElements's local)
// the config's slot, where the base keeps it alone nearest the guard (-0x34), every other slot
// 0x10 off; and the base splats the radius and builds the perpendicular before the call, its
// normalization after, where this spills the radius and splits the perpendicular.
const hknpShape *hknpVehicleLinearCastWheelCollide::FUN_00178620(float width, float radius)
{
    const Vec4 axisZ = _mm_setr_ps(0.0f, 0.0f, 1.0f, 0.0f);
    const Vec4 vertexA = _mm_mul_ps(_mm_set1_ps(width * 0.25f), axisZ);
    const Vec4 vertexB = _mm_mul_ps(_mm_set1_ps(width * -0.25f), axisZ);
    hkArray<hkVector4> vertices(64);
    const Vec4 axis = normalized3(_mm_sub_ps(vertexB, vertexA));
    const Vec4 step = _mm_mul_ps(_mm_mul_ps(D_14b2060[4], D_14b2060[50]), _mm_set1_ps(1.0f / 32));
    const Vec4 perpendicular = perpendicular3(axis);

    const Vec4 radial = _mm_mul_ps(_mm_set1_ps(radius), normalized3(perpendicular));
    for (int i = 0; i < 32; i++) {
        hkQuaternion rotation;
        rotation.FUN_00019ff0(axis, _mm_mul_ps(step, simdFromInt(i)));
        const Vec4 rotated = rotatedDir(rotation, radial);
        vertices[i].quad = _mm_add_ps(vertexA, rotated);
        vertices[i + 32].quad = _mm_add_ps(vertexB, rotated);
    }

    const hkStridedVertices stridedVertices(vertices);
    ConvexBuildConfig000451e0 config;
    return FUN_00044710(stridedVertices, 0.01f, config);
}

/* src/libs/havok/Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHull.cpp:
 * the file its assert names (config/homes.base.txt, FUN_000b8d50). */
#include "tlg_lib_unknown.h"

int hkgpConvexHull::FUN_000b6bf0() const /* derived name */
{
    return data->numVertices;
}

hkgpConvexHullTriangle *hkgpConvexHull::FUN_000b6d10() const /* derived name */
{
    return data->firstTriangle;
}

hkgpConvexHullVertex *hkgpConvexHull::FUN_000b6d20(const hkgpConvexHullTriangle *triangle,
                                                   int index) const /* derived name */
{
    return triangle->vertices[index];
}

/* derived name: the hull's dimension (called at 0x152512, 0x15253d and
 * 0x1525bf by hknpConvexPolytopeShape's builder). */
int hkgpConvexHull::FUN_000b8a80() const /* derived name */
{
    return data->dimension;
}

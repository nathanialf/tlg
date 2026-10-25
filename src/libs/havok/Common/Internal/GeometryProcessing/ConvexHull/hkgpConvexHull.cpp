/* src/libs/havok/Common/Internal/GeometryProcessing/ConvexHull/hkgpConvexHull.cpp:
 * the file its assert names (config/homes.base.txt, FUN_000b8d50). */
#include "tlg_types.h"

/* derived names: a reference-counted convex hull (its constructor
 * FUN_000b3490 stores the vtable address point 0x16a3be0 and allocates its
 * 0x1f0-byte data) with the data behind a pointer at +0x10 (the homed
 * FUN_000b8d50 reads the data's flags at +0x1ec and +0x1ee and its
 * dimension at +0x1e0, which FUN_000b8a80 returns). The class takes its name
 * from the file. hknpConvexPolytopeShape's builder (0x152593, 0x1527f8,
 * 0x152866) compares the count at +0x38 against its vertex limit (at most
 * 252) and reduces the hull with FUN_000b4e50 when it is over; it walks the
 * triangles from the first (FUN_000b6d10, the pointer at +0x48 of the data)
 * and reads each one's three vertices (FUN_000b6d20, the pointers from +0x10
 * of the triangle) into positions (0xbc840). */
struct hkgpConvexHullVertex; /* derived name */

struct hkgpConvexHullTriangle /* derived name */
{
    u8 unknown0[0x10];
    hkgpConvexHullVertex *vertices[3]; /* derived name */
};

struct hkgpConvexHullData /* derived name */
{
    u8 unknown0[0x38];
    s32 numVertices; /* derived name */
    u8 unknown3c[0xc];
    hkgpConvexHullTriangle *firstTriangle; /* derived name */
};

class hkgpConvexHull /* derived name */
{
  public:
    virtual ~hkgpConvexHull();

    int FUN_000b6bf0() const;                     /* derived name */
    hkgpConvexHullTriangle *FUN_000b6d10() const; /* derived name */
    hkgpConvexHullVertex *FUN_000b6d20(const hkgpConvexHullTriangle *triangle,
                                       int index) const; /* derived name */

    u8 unknown8[8];
    hkgpConvexHullData *data; /* derived name */
};

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

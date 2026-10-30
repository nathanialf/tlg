/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 17 of hknpConvexPolytopeShape's vtable (0x16a4460, kept
 * by hknpTriangleShape's 0x169b670): the smallest of the faces' minimum half
 * angles, each read through slot 14, as radians (the low seven bits of the
 * byte count steps of pi / 510 after doubling); with no faces, the largest. */
float hknpConvexPolytopeShape::FUN_001540a0() const /* derived name */
{
    int numFaces = faces.getSize();
    u8 minAngle = 0xff;
    for (int i = 0; i < numFaces; i++) {
        Vec4 plane;
        hknpFaceAngle angle;
        unknownVirtual14(i, &plane, &angle);
        minAngle = u8(hkMath::min2(int(minAngle), int(angle.value)));
    }
    return float((minAngle & 0x7f) << 1) * (HK_REAL_PI / 510.0f);
}

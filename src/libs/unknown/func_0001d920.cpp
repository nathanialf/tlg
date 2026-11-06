/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkcdPlanarGeometryPrimitives::Plane's type info (0x57ba4e0):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
static void finishLoadedObjecthkcdPlanarGeometryPrimitivesPlane(void *object,
                                                                int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_00095aa0(static_cast<hkcdPlanarGeometryPrimitivesPlane *>(object), flag);
}

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x1c1e0. */
static void cleanupLoadedObjecthkcdPlanarGeometryPrimitivesPlane(void *object) /* derived name */
{
    static_cast<hkcdPlanarGeometryPrimitivesPlane *>(object)->~hkcdPlanarGeometryPrimitivesPlane();
}

/* This file's static initializer (0x1d920): hkcdPlanarGeometryPrimitives::
 * Plane's reflection (hkClass 0x57ba490: no parent, its two members), then
 * its type info (the finish callback 0x1d900, no vtable). */
const hkClass D_57ba490("hkcdPlanarGeometryPrimitivesPlane", 0,
                        sizeof(hkcdPlanarGeometryPrimitivesPlane), 0, 0, 0, 0, D_168f9a0, 2, 0, 0,
                        0, 0);
extern const hkTypeInfo D_57ba4e0;
const hkTypeInfo D_57ba4e0("hkcdPlanarGeometryPrimitivesPlane",
                           "!hkcdPlanarGeometryPrimitives::Plane",
                           finishLoadedObjecthkcdPlanarGeometryPrimitivesPlane,
                           cleanupLoadedObjecthkcdPlanarGeometryPrimitivesPlane, 0,
                           sizeof(hkcdPlanarGeometryPrimitivesPlane));

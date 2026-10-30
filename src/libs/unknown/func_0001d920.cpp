/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The plane's loaded-object cleanup: nothing to clean up (the linker folded
 * it into the shared empty body 0x1c1e0, FUN_0001c1e0). */
void FUN_0001c1e0(void *object) {}

/* This file's static initializer (0x1d920): hkcdPlanarGeometryPrimitives::
 * Plane's reflection (hkClass 0x57ba490: no parent, its two members), then
 * its type info (the finish callback 0x1d900, no vtable). */
const hkClass D_57ba490("hkcdPlanarGeometryPrimitivesPlane", 0,
                        sizeof(hkcdPlanarGeometryPrimitivesPlane), 0, 0, 0, 0, D_168f9a0, 2, 0, 0,
                        0, 0);
extern const hkTypeInfo D_57ba4e0;
const hkTypeInfo D_57ba4e0("hkcdPlanarGeometryPrimitivesPlane",
                           "!hkcdPlanarGeometryPrimitives::Plane", FUN_0001d900, FUN_0001c1e0, 0,
                           sizeof(hkcdPlanarGeometryPrimitivesPlane));

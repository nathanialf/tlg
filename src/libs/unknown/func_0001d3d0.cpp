/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

extern const hkClassMember
    D_168f4a0[]; /* derived name: hkcdPlanarGeometryPlanesCollection's records */
extern const hkClassEnum D_168f5b0[]; /* derived name: hkcdPlanarGeometryPlanesCollection's enums */

void FUN_0001d3b0(void *object, int finishing); /* derived name */
void FUN_000002d0(void *object);                /* derived name */

/* The class's vtable, read from an object its out-of-line finish
 * constructor builds on the stack. derived name. */
static const void *vtableOfhkcdPlanarGeometryPlanesCollection() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkcdPlanarGeometryPlanesCollection)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkcdPlanarGeometryPlanesCollection(flag);
    return object.vtable;
}

/* This file's static initializer (0x1d3d0): hkcdPlanarGeometryPlanesCollection's reflection,
 * hkReferencedObject's as the parent, four members, its enum,
 * then its type info (its finish callback, the destructor, the vtable). */
const hkClass D_57ba290("hkcdPlanarGeometryPlanesCollection", &D_57b8640,
                        sizeof(hkcdPlanarGeometryPlanesCollection), 0, 0, D_168f5b0, 1, D_168f4a0,
                        4, 0, 0, 0, 0);
extern const hkTypeInfo D_57ba2e0;
const hkTypeInfo D_57ba2e0("hkcdPlanarGeometryPlanesCollection",
                           "!hkcdPlanarGeometryPlanesCollection", FUN_0001d3b0, FUN_000002d0,
                           vtableOfhkcdPlanarGeometryPlanesCollection(),
                           sizeof(hkcdPlanarGeometryPlanesCollection));

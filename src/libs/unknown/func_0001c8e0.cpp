/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the finish callback of hkcdPlanarGeometryPrimitivesCollection28's
 * type info (0x57b9e40): construct the collection in place from a loaded
 * image through its inline finish constructor, which has nothing to fix up
 * but the vtable. The collection's destructors (0x1c8e0, 0x1c930), inline
 * in its class, are emitted here with its vtable. */
static void
finishLoadedObjecthkcdPlanarGeometryPrimitivesCollection28(void *object,
                                                           int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkcdPlanarGeometryPrimitivesCollection28(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void
cleanupLoadedObjecthkcdPlanarGeometryPrimitivesCollection28(void *object) /* derived name */
{
    static_cast<hkcdPlanarGeometryPrimitivesCollection28 *>(object)
        ->~hkcdPlanarGeometryPrimitivesCollection28();
}

/* The address of the collection's vtable, read from an object finished in
 * a buffer (folded to the address point). */
static const void *vtableOfCollection() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkcdPlanarGeometryPrimitivesCollection28)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hkcdPlanarGeometryPrimitivesCollection28(flag);
    return object.vtable;
}

/* This file's static initializer (0x1c9b0): the collection's reflection
 * over hkReferencedObject's, its four members, then its type info. */
const hkClass D_57b9df0("hkcdPlanarGeometryPrimitivesCollection28", &D_57b8640,
                        sizeof(hkcdPlanarGeometryPrimitivesCollection28), 0, 0, 0, 0, D_168eec0, 4,
                        0, 0, 0, 0);
extern const hkTypeInfo D_57b9e40;
const hkTypeInfo D_57b9e40("hkcdPlanarGeometryPrimitivesCollection28",
                           "!hkcdPlanarGeometryPrimitivesCollection28_typename",
                           finishLoadedObjecthkcdPlanarGeometryPrimitivesCollection28,
                           cleanupLoadedObjecthkcdPlanarGeometryPrimitivesCollection28,
                           vtableOfCollection(), sizeof(hkcdPlanarGeometryPrimitivesCollection28));

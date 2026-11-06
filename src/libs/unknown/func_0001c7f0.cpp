/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the finish callback of hkcdPlanarGeometryPolygonCollection's type info (0x57b9dd0):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
static void finishLoadedObjecthkcdPlanarGeometryPolygonCollection(void *object,
                                                                  int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkcdPlanarGeometryPolygonCollection(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthkcdPlanarGeometryPolygonCollection(void *object) /* derived name */
{
    static_cast<hkcdPlanarGeometryPolygonCollection *>(object)
        ->~hkcdPlanarGeometryPolygonCollection();
}

/* The class's vtable, read from an object its out-of-line finish
 * constructor builds on the stack. derived name. */
static const void *vtableOfhkcdPlanarGeometryPolygonCollection() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkcdPlanarGeometryPolygonCollection)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkcdPlanarGeometryPolygonCollection(flag);
    return object.vtable;
}

/* This file's static initializer (0x1c7f0): hkcdPlanarGeometryPolygonCollection's
 * reflection, the primitives collection's as the parent, no members of its
 * own, then its type info (its finish callback, the destructor, the vtable). */
const hkClass D_57b9d70("hkcdPlanarGeometryPolygonCollection", &D_57b9df0,
                        sizeof(hkcdPlanarGeometryPolygonCollection), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
extern const hkTypeInfo D_57b9dc0;
const hkTypeInfo D_57b9dc0("hkcdPlanarGeometryPolygonCollection",
                           "!hkcdPlanarGeometryPolygonCollection",
                           finishLoadedObjecthkcdPlanarGeometryPolygonCollection,
                           cleanupLoadedObjecthkcdPlanarGeometryPolygonCollection,
                           vtableOfhkcdPlanarGeometryPolygonCollection(),
                           sizeof(hkcdPlanarGeometryPolygonCollection));

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkcdPlanarGeometry's type info (0x57ba160):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
static void finishLoadedObjecthkcdPlanarGeometry(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkcdPlanarGeometry(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthkcdPlanarGeometry(void *object) /* derived name */
{
    static_cast<hkcdPlanarGeometry *>(object)->~hkcdPlanarGeometry();
}

extern const hkClassMember D_168f330[]; /* derived name: hkcdPlanarGeometry's records */

/* The address of hkcdPlanarGeometry's vtable, read from an object finished in a 16-byte
 * aligned buffer (the finish constructor is out of line, 0x9a860, so the object is built on
 * the stack, as hkcdStaticAabbTree's in func_0001ff50.cpp). */
static const void *vtableOfhkcdPlanarGeometry() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkcdPlanarGeometry)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkcdPlanarGeometry(flag);
    return object.vtable;
}

/* This file's static initializer (0x1cf80): hkcdPlanarGeometry's reflection over
 * hkcdPlanarEntity's (version 0), its three members, then its type info. */
const hkClass D_57ba110("hkcdPlanarGeometry", &D_57ba190, sizeof(hkcdPlanarGeometry), 0, 0, 0, 0,
                        D_168f330, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57ba160;
const hkTypeInfo D_57ba160("hkcdPlanarGeometry", "!hkcdPlanarGeometry",
                           finishLoadedObjecthkcdPlanarGeometry,
                           cleanupLoadedObjecthkcdPlanarGeometry, vtableOfhkcdPlanarGeometry(),
                           sizeof(hkcdPlanarGeometry));

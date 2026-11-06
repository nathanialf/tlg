/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the finish callback of hknpMaterialLibrary's type info
 * (registered at 0x6156d): construct the object in place from a loaded
 * image through its inline finish constructor. */
static void finishLoadedObjecthknpMaterialLibrary(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpMaterialLibrary(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthknpMaterialLibrary(void *object) /* derived name */
{
    static_cast<hknpMaterialLibrary *>(object)->~hknpMaterialLibrary();
}

extern const hkClassMember D_1699580[]; /* derived name: hknpMaterialLibrary's records */

/* The address of hknpMaterialLibrary's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhknpMaterialLibrary() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpMaterialLibrary)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hknpMaterialLibrary(flag);
    return object.vtable;
}

/* This file's static initializer (0x614c0): hknpMaterialLibrary's reflection over hkReferencedObject's, its 4 members, then its type info. */
const hkClass D_57c1788("hknpMaterialLibrary", &D_57b8640, sizeof(hknpMaterialLibrary), 0, 0, 0, 0,
                        D_1699580, 4, 0, 0, 0, 0);
extern const hkTypeInfo D_57c17d8;
const hkTypeInfo D_57c17d8("hknpMaterialLibrary", "!hknpMaterialLibrary",
                           finishLoadedObjecthknpMaterialLibrary,
                           cleanupLoadedObjecthknpMaterialLibrary, vtableOfhknpMaterialLibrary(),
                           sizeof(hknpMaterialLibrary));

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the finish callback of hknpBodyQualityLibrary's type info (0x57c1a78):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
static void finishLoadedObjecthknpBodyQualityLibrary(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpBodyQualityLibrary(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthknpBodyQualityLibrary(void *object) /* derived name */
{
    static_cast<hknpBodyQualityLibrary *>(object)->~hknpBodyQualityLibrary();
}

extern const hkClassMember D_16997a0[]; /* derived name: hknpBodyQualityLibrary's records */

/* The class's vtable, read from an object its out-of-line finish
 * constructor builds on the stack. derived name. */
static const void *vtableOfhknpBodyQualityLibrary() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpBodyQualityLibrary)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpBodyQualityLibrary(flag);
    return object.vtable;
}

/* This file's static initializer (0x61e00): hknpBodyQualityLibrary's reflection,
 * hkReferencedObject's as the parent, two members,
 * then its type info (its finish callback, the destructor, the vtable). */
const hkClass D_57c1a28("hknpBodyQualityLibrary", &D_57b8640, sizeof(hknpBodyQualityLibrary), 0, 0,
                        0, 0, D_16997a0, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57c1a78;
const hkTypeInfo D_57c1a78("hknpBodyQualityLibrary", "!hknpBodyQualityLibrary",
                           finishLoadedObjecthknpBodyQualityLibrary,
                           cleanupLoadedObjecthknpBodyQualityLibrary,
                           vtableOfhknpBodyQualityLibrary(), sizeof(hknpBodyQualityLibrary));

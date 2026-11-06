/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hknpMotionPropertiesLibrary's type info (0x57bf0a0):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
static void finishLoadedObjecthknpMotionPropertiesLibrary(void *object,
                                                          int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpMotionPropertiesLibrary(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthknpMotionPropertiesLibrary(void *object) /* derived name */
{
    static_cast<hknpMotionPropertiesLibrary *>(object)->~hknpMotionPropertiesLibrary();
}

extern const hkClassMember D_1694290[]; /* derived name: hknpMotionPropertiesLibrary's records */

/* The class's vtable, read from an object its out-of-line finish
 * constructor builds on the stack. derived name. */
static const void *vtableOfhknpMotionPropertiesLibrary() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpMotionPropertiesLibrary)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpMotionPropertiesLibrary(flag);
    return object.vtable;
}

/* This file's static initializer (0x38c30): hknpMotionPropertiesLibrary's
 * reflection, hkReferencedObject's as the parent, its four members, then its
 * type info (its finish callback, the destructor, the vtable). */
const hkClass D_57bf050("hknpMotionPropertiesLibrary", &D_57b8640,
                        sizeof(hknpMotionPropertiesLibrary), 0, 0, 0, 0, D_1694290, 4, 0, 0, 0, 0);
extern const hkTypeInfo D_57bf0a0;
const hkTypeInfo D_57bf0a0("hknpMotionPropertiesLibrary", "!hknpMotionPropertiesLibrary",
                           finishLoadedObjecthknpMotionPropertiesLibrary,
                           cleanupLoadedObjecthknpMotionPropertiesLibrary,
                           vtableOfhknpMotionPropertiesLibrary(),
                           sizeof(hknpMotionPropertiesLibrary));

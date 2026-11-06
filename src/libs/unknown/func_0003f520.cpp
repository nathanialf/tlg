/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hknpBodyReference's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
static void finishLoadedObjecthknpBodyReference(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpBodyReference(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthknpBodyReference(void *object) /* derived name */
{
    static_cast<hknpBodyReference *>(object)->~hknpBodyReference();
}

extern const hkClassMember D_1696d60[]; /* derived name: hknpBodyReference's records */

/* The address of hknpBodyReference's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhknpBodyReference() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hknpBodyReference)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hknpBodyReference(flag);
    return object.vtable;
}

/* This file's static initializer (0x3f540): hknpBodyReference's reflection over hkReferencedObject's, its one member, then its type info. */
const hkClass D_57c0b28("hknpBodyReference", &D_57b8640, sizeof(hknpBodyReference), 0, 0, 0, 0,
                        D_1696d60, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57c0b78;
const hkTypeInfo D_57c0b78("hknpBodyReference", "!hknpBodyReference",
                           finishLoadedObjecthknpBodyReference,
                           cleanupLoadedObjecthknpBodyReference, vtableOfhknpBodyReference(),
                           sizeof(hknpBodyReference));

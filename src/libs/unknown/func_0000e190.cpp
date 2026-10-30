/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkReferencedObject's type info
 * (0x57b8690, registered at 0xe1b0): construct the object in place from a
 * loaded image through its inline finish constructor, which has nothing to
 * fix up but the vtable. */
void FUN_0000e190(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkReferencedObject(flag);
}

/* hkReferencedObject's cleanup callback: the virtual destructor (the shared
 * body 0x2d0). */
void FUN_000002d0(void *object);

/* The address of hkReferencedObject's vtable, read from an object finished
 * in a buffer (folded to the address point). */
static const void *vtableOfhkReferencedObject() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkReferencedObject)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hkReferencedObject(flag);
    return object.vtable;
}

/* This file's static initializer (0xe1b0): hkReferencedObject's reflection
 * over hkBaseObject's, its one member, then its type info. */
const hkClass D_57b8640("hkReferencedObject", &D_57b86c0, sizeof(hkReferencedObject), 0, 0, 0, 0,
                        D_168d980, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57b8690;
const hkTypeInfo D_57b8690("hkReferencedObject", "!hkReferencedObject", FUN_0000e190, FUN_000002d0,
                           vtableOfhkReferencedObject(), sizeof(hkReferencedObject));

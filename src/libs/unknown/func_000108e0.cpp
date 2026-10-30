/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkStringObject's type info
 * (0x109bb): construct the object in place from a loaded image. */
void FUN_000108e0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkStringObject(flag);
}

/* hkStringObject's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_168e120[]; /* derived name: hkStringObject's record */

/* The address of hkStringObject's vtable, read from an object finished in a 16-byte aligned
 * buffer: the string's finish constructor is out of line (0xe5c0), so the object is built on
 * the stack and its vtable read back after the call. */
static const void *vtableOfhkStringObject() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkStringObject)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkStringObject(flag);
    return object.vtable;
}

/* This file's static initializer (0x10910): hkStringObject's reflection over
 * hkReferencedObject's (version 0), its one member, then its type info. */
const hkClass D_57b91b8("hkStringObject", &D_57b8640, sizeof(hkStringObject), 0, 0, 0, 0, D_168e120,
                        1, 0, 0, 0, 0);
extern const hkTypeInfo D_57b9208;
const hkTypeInfo D_57b9208("hkStringObject", "!hkStringObject", FUN_000108e0, FUN_000002d0,
                           vtableOfhkStringObject(), sizeof(hkStringObject));

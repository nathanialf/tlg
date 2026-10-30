/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkxCamera's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
void FUN_0008a270(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxCamera(flag);
}

/* hkxCamera's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_16a1ab0[]; /* derived name: hkxCamera's records */

/* The address of hkxCamera's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhkxCamera() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkxCamera)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hkxCamera(flag);
    return object.vtable;
}

/* This file's static initializer (0x8a290): hkxCamera's reflection over hkReferencedObject's, its 7 members, then its type info. */
const hkClass D_57c72b8("hkxCamera", &D_57b8640, sizeof(hkxCamera), 0, 0, 0, 0, D_16a1ab0, 7, 0, 0,
                        0, 1);
extern const hkTypeInfo D_57c7308;
const hkTypeInfo D_57c7308("hkxCamera", "!hkxCamera", FUN_0008a270, FUN_000002d0,
                           vtableOfhkxCamera(), sizeof(hkxCamera));

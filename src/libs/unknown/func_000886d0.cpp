/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkxAnimatedQuaternion's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
void FUN_000886d0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxAnimatedQuaternion(flag);
}

/* hkxAnimatedQuaternion's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_16a13d0[]; /* derived name: hkxAnimatedQuaternion's records */

/* The address of hkxAnimatedQuaternion's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhkxAnimatedQuaternion() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkxAnimatedQuaternion)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hkxAnimatedQuaternion(flag);
    return object.vtable;
}

/* This file's static initializer (0x886f0): hkxAnimatedQuaternion's reflection over hkReferencedObject's, its one member, then its type info. */
const hkClass D_57c6be8("hkxAnimatedQuaternion", &D_57b8640, sizeof(hkxAnimatedQuaternion), 0, 0, 0,
                        0, D_16a13d0, 1, 0, 0, 0, 2);
extern const hkTypeInfo D_57c6c38;
const hkTypeInfo D_57c6c38("hkxAnimatedQuaternion", "!hkxAnimatedQuaternion", FUN_000886d0,
                           FUN_000002d0, vtableOfhkxAnimatedQuaternion(),
                           sizeof(hkxAnimatedQuaternion));

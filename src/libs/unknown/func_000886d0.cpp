/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkxAnimatedQuaternion's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
static void finishLoadedObjecthkxAnimatedQuaternion(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxAnimatedQuaternion(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthkxAnimatedQuaternion(void *object) /* derived name */
{
    static_cast<hkxAnimatedQuaternion *>(object)->~hkxAnimatedQuaternion();
}

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
const hkTypeInfo D_57c6c38("hkxAnimatedQuaternion", "!hkxAnimatedQuaternion",
                           finishLoadedObjecthkxAnimatedQuaternion,
                           cleanupLoadedObjecthkxAnimatedQuaternion,
                           vtableOfhkxAnimatedQuaternion(), sizeof(hkxAnimatedQuaternion));

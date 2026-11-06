/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the object constructed in place from a loaded image through its
 * inline finish constructor, which has nothing to fix up but the vtable
 * (the finish callback kept at 0x86d70), and destroyed through its virtual
 * destructor (the body the linker folded, 0x2d0). */
static void finishLoadedObjecthkxAnimatedVector(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxAnimatedVector(flag);
}

static void cleanupLoadedObjecthkxAnimatedVector(void *object) /* derived name */
{
    static_cast<hkxAnimatedVector *>(object)->~hkxAnimatedVector();
}

/* The address of hkxAnimatedVector's vtable, read from an object finished
 * in a buffer (folded to the address point). */
static const void *vtableOfhkxAnimatedVector() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkxAnimatedVector)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hkxAnimatedVector(flag);
    return object.vtable;
}

/* This file's static initializer (0x86d90): hkxAnimatedVector's two member
 * records, built at run time from the hint's enum pointer, then its
 * reflection over hkReferencedObject's (version 2) and its type info with
 * its vtable. */
static hkClassMember D_57c6600[] = {
    {"vectors", 0, 0, hkClassMember::TYPE_ARRAY, hkClassMember::TYPE_REAL, 0, 0, 0x10, 0},
    {"hint", 0, D_16dc6d0, hkClassMember::TYPE_ENUM, hkClassMember::TYPE_UINT8, 0, 0, 0x20, 0}};
const hkClass D_57c6580("hkxAnimatedVector", &D_57b8640, sizeof(hkxAnimatedVector), 0, 0, 0, 0,
                        D_57c6600, 2, 0, 0, 0, 2);
extern const hkTypeInfo D_57c65d0;
const hkTypeInfo D_57c65d0("hkxAnimatedVector", "!hkxAnimatedVector",
                           finishLoadedObjecthkxAnimatedVector,
                           cleanupLoadedObjecthkxAnimatedVector, vtableOfhkxAnimatedVector(),
                           sizeof(hkxAnimatedVector));

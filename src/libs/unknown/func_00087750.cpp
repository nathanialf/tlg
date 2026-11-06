/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the finish callback of hkxSparselyAnimatedString's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
static void finishLoadedObjecthkxSparselyAnimatedString(void *object,
                                                        int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxSparselyAnimatedString(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes',
 * 0x2d0). */
static void cleanupLoadedObjecthkxSparselyAnimatedString(void *object) /* derived name */
{
    static_cast<hkxSparselyAnimatedString *>(object)->~hkxSparselyAnimatedString();
}

extern const hkClassMember D_16a0ea0[]; /* derived name: hkxSparselyAnimatedString's records */

/* The address of hkxSparselyAnimatedString's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhkxSparselyAnimatedString() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkxSparselyAnimatedString)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hkxSparselyAnimatedString(flag);
    return object.vtable;
}

/* This file's static initializer (0x87770): hkxSparselyAnimatedString's reflection over hkReferencedObject's, its 2 members, then its type info. */
const hkClass D_57c6750("hkxSparselyAnimatedString", &D_57b8640, sizeof(hkxSparselyAnimatedString),
                        0, 0, 0, 0, D_16a0ea0, 2, 0, 0, 0, 2);
extern const hkTypeInfo D_57c67a0;
const hkTypeInfo D_57c67a0("hkxSparselyAnimatedString", "!hkxSparselyAnimatedString",
                           finishLoadedObjecthkxSparselyAnimatedString,
                           cleanupLoadedObjecthkxSparselyAnimatedString,
                           vtableOfhkxSparselyAnimatedString(), sizeof(hkxSparselyAnimatedString));

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the finish callback of hkxSparselyAnimatedInt's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
void FUN_00088900(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxSparselyAnimatedInt(flag);
}

/* hkxSparselyAnimatedInt's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_16a1440[]; /* derived name: hkxSparselyAnimatedInt's records */

/* The address of hkxSparselyAnimatedInt's vtable, read from an object finished in a buffer
 * (folded to the address point). */
static const void *vtableOfhkxSparselyAnimatedInt() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkxSparselyAnimatedInt)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hkxSparselyAnimatedInt(flag);
    return object.vtable;
}

/* This file's static initializer (0x88920): hkxSparselyAnimatedInt's reflection over hkReferencedObject's, its 2 members, then its type info. */
const hkClass D_57c6c68("hkxSparselyAnimatedInt", &D_57b8640, sizeof(hkxSparselyAnimatedInt), 0, 0,
                        0, 0, D_16a1440, 2, 0, 0, 0, 1);
extern const hkTypeInfo D_57c6cb8;
const hkTypeInfo D_57c6cb8("hkxSparselyAnimatedInt", "!hkxSparselyAnimatedInt", FUN_00088900,
                           FUN_000002d0, vtableOfhkxSparselyAnimatedInt(),
                           sizeof(hkxSparselyAnimatedInt));

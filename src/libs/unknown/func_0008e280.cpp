/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the finish callback of hkxSparselyAnimatedBool's type info (0x57c8280):
 * construct the object in place from a loaded image through its inline
 * finish constructor, which has nothing to fix up but the vtable. */
void FUN_0008e280(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxSparselyAnimatedBool(flag);
}

/* hkxSparselyAnimatedBool's loaded-object cleanup: the virtual destructor (the linker
 * folded it with the other classes' identical body, 0x2d0, FUN_000002d0). */
void FUN_000002d0(void *object)
{
    static_cast<hkxSparselyAnimatedBool *>(object)->~hkxSparselyAnimatedBool();
}

/* The class's vtable, read from an object its finish constructor builds
 * (cookbook 166). derived name. */
static const void *vtableOfhkxSparselyAnimatedBool() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkxSparselyAnimatedBool)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxSparselyAnimatedBool(flag);
    return object.vtable;
}

/* This file's static initializer (0x8e2a0): hkxSparselyAnimatedBool's reflection,
 * hkReferencedObject's as the parent, its two members, version 1, then its
 * type info (its finish callback, the destructor, the vtable). */
const hkClass D_57c8230("hkxSparselyAnimatedBool", &D_57b8640, sizeof(hkxSparselyAnimatedBool), 0,
                        0, 0, 0, D_16a2b70, 2, 0, 0, 0, 1);
extern const hkTypeInfo D_57c8280;
const hkTypeInfo D_57c8280("hkxSparselyAnimatedBool", "!hkxSparselyAnimatedBool", FUN_0008e280,
                           FUN_000002d0, vtableOfhkxSparselyAnimatedBool(),
                           sizeof(hkxSparselyAnimatedBool));

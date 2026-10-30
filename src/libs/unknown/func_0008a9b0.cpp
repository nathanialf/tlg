/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkxSkinBinding's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
void FUN_0008a9b0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxSkinBinding(flag);
}

/* hkxSkinBinding's loaded-object cleanup: the virtual destructor (the linker
 * folded it with the other classes' identical body, 0x2d0, FUN_000002d0). */
void FUN_000002d0(void *object)
{
    static_cast<hkxSkinBinding *>(object)->~hkxSkinBinding();
}

/* The class's vtable, read from an object its finish constructor builds
 * (cookbook 166). derived name. */
static const void *vtableOfhkxSkinBinding() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkxSkinBinding)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxSkinBinding(flag);
    return object.vtable;
}

/* This file's static initializer (0x8a9d0): hkxSkinBinding's reflection,
 * hkReferencedObject's as the parent, its four members, version 2, then its
 * type info (its finish callback, the destructor, the vtable). */
const hkClass D_57c74b0("hkxSkinBinding", &D_57b8640, sizeof(hkxSkinBinding), 0, 0, 0, 0, D_16a1cf0,
                        4, 0, 0, 0, 2);
extern const hkTypeInfo D_57c7500;
const hkTypeInfo D_57c7500("hkxSkinBinding", "!hkxSkinBinding", FUN_0008a9b0, FUN_000002d0,
                           vtableOfhkxSkinBinding(), sizeof(hkxSkinBinding));

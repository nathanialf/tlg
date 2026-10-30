/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkxAttributeHolder's type info: construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
void FUN_0008b390(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxAttributeHolder(flag);
}

/* hkxAttributeHolder's loaded-object cleanup: the virtual destructor (the linker
 * folded it with the other classes' identical body, 0x2d0, FUN_000002d0). */
void FUN_000002d0(void *object)
{
    static_cast<hkxAttributeHolder *>(object)->~hkxAttributeHolder();
}

/* The class's vtable, read from an object its finish constructor builds
 * (cookbook 166). derived name. */
static const void *vtableOfhkxAttributeHolder() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkxAttributeHolder)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxAttributeHolder(flag);
    return object.vtable;
}

/* This file's static initializer (0x8b3b0): hkxAttributeHolder's reflection,
 * hkReferencedObject's as the parent, its one member, version 2, then its
 * type info (its finish callback, the destructor, the vtable). */
const hkClass D_57c76b0("hkxAttributeHolder", &D_57b8640, sizeof(hkxAttributeHolder), 0, 0, 0, 0,
                        D_16a1f70, 1, 0, 0, 0, 2);
extern const hkTypeInfo D_57c7700;
const hkTypeInfo D_57c7700("hkxAttributeHolder", "!hkxAttributeHolder", FUN_0008b390, FUN_000002d0,
                           vtableOfhkxAttributeHolder(), sizeof(hkxAttributeHolder));

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkxMeshSection's type info (0x57c8200):
 * construct the object in place from a loaded image through its inline
 * finish constructor, which has nothing to fix up but the vtable. */
void FUN_0008e000(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxMeshSection(flag);
}

/* hkxMeshSection's loaded-object cleanup: the virtual destructor (the linker
 * folded it with the other classes' identical body, 0x2d0, FUN_000002d0). */
void FUN_000002d0(void *object)
{
    static_cast<hkxMeshSection *>(object)->~hkxMeshSection();
}

/* The class's vtable, read from an object its finish constructor builds
 * (cookbook 166). derived name. */
static const void *vtableOfhkxMeshSection() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkxMeshSection)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxMeshSection(flag);
    return object.vtable;
}

/* This file's static initializer (0x8e020): hkxMeshSection's reflection,
 * hkReferencedObject's as the parent, its seven members, version 5, then its
 * type info (its finish callback, the destructor, the vtable). */
const hkClass D_57c81b0("hkxMeshSection", &D_57b8640, sizeof(hkxMeshSection), 0, 0, 0, 0, D_16a2a10,
                        7, 0, 0, 0, 5);
extern const hkTypeInfo D_57c8200;
const hkTypeInfo D_57c8200("hkxMeshSection", "!hkxMeshSection", FUN_0008e000, FUN_000002d0,
                           vtableOfhkxMeshSection(), sizeof(hkxMeshSection));

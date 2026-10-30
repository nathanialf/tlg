/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkxAttributeGroup's finish callback: the group finished in place, its
 * name (the linker folded it with hknpMaterialDescriptor's finish, the
 * body 0x6c800). */
void FUN_0006c800(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxAttributeGroup(flag);
}

/* This file's static initializer (0x88b00): hkxAttributeGroup's reflection
 * (hkClass 0x57c6ce8: no parent, its two members), then its type info (the
 * cleanup callback 0x88a00, no vtable). */
const hkClass D_57c6ce8("hkxAttributeGroup", 0, sizeof(hkxAttributeGroup), 0, 0, 0, 0, D_16a1490, 2,
                        0, 0, 0, 0);
extern const hkTypeInfo D_57c6d38;
const hkTypeInfo D_57c6d38("hkxAttributeGroup", "!hkxAttributeGroup", FUN_0006c800, FUN_00088a00, 0,
                           sizeof(hkxAttributeGroup));

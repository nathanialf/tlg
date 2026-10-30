/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkxAttribute's loaded-object cleanup: the destructor (the linker folded it
 * with hknpMaterialDescriptor's identical body, 0x66e80). */
void FUN_00066e80(void *object)
{
    static_cast<hkxAttribute *>(object)->~hkxAttribute();
}

/* This file's static initializer (0x8b890): hkxAttribute's reflection, no
 * parent, its one enum and two members, version 1, then its type info (the
 * finish callback FUN_0008b870, no vtable). */
const hkClass D_57c78b0("hkxAttribute", 0, sizeof(hkxAttribute), 0, 0, D_16a2490, 1, D_16a23e0, 2,
                        0, 0, 0, 1);
extern const hkTypeInfo D_57c7900;
const hkTypeInfo D_57c7900("hkxAttribute", "!hkxAttribute", FUN_0008b870, FUN_00066e80, 0,
                           sizeof(hkxAttribute));

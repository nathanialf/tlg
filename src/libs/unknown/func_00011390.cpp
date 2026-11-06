/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0xe5c0. */
static void cleanupLoadedObjecthkAabbHalf(void *object) /* derived name */
{
    static_cast<hkAabbHalf *>(object)->~hkAabbHalf();
}

/* This file's static initializer (0x11390): hkAabbHalf's reflection, no
 * parent, its one member, version 1, then its type info (no finish
 * callback, no vtable). */
const hkClass D_57b9238("hkAabbHalf", 0, sizeof(hkAabbHalf), 0, 0, 0, 0, D_168e150, 1, 0, 0, 0, 1);
extern const hkTypeInfo D_57b9288;
const hkTypeInfo D_57b9288("hkAabbHalf", "!hkAabbHalf", 0, cleanupLoadedObjecthkAabbHalf, 0,
                           sizeof(hkAabbHalf));

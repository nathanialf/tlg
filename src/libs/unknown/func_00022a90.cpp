/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x1c1e0. */
static void cleanupLoadedObjecthkCompressedMassProperties(void *object) /* derived name */
{
    static_cast<hkCompressedMassProperties *>(object)->~hkCompressedMassProperties();
}

/* This file's static initializer (0x22a90): hkCompressedMassProperties's reflection, no parent
 * and its members, then its type info (no finish callback, no vtable). */
const hkClass D_57bc9e0("hkCompressedMassProperties", 0, sizeof(hkCompressedMassProperties), 0, 0,
                        0, 0, D_1691090, 5, 0, 0, 0, 0);
extern const hkTypeInfo D_57bca30;
const hkTypeInfo D_57bca30("hkCompressedMassProperties", "!hkCompressedMassProperties", 0,
                           cleanupLoadedObjecthkCompressedMassProperties, 0,
                           sizeof(hkCompressedMassProperties));

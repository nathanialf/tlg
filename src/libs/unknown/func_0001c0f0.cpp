/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0xe5c0. */
static void cleanupLoadedObjecthkFloat16(void *object) /* derived name */
{
    static_cast<hkFloat16 *>(object)->~hkFloat16();
}

/* This file's static initializer (0x1c0f0): hkFloat16's reflection, no parent
 * and its members, then its type info (no finish callback, no vtable). */
const hkClass D_57b9ba0("hkFloat16", 0, sizeof(hkFloat16), 0, 0, 0, 0, D_168eb40, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57b9bf0;
const hkTypeInfo D_57b9bf0("hkFloat16", "!hkFloat16", 0, cleanupLoadedObjecthkFloat16, 0,
                           sizeof(hkFloat16));

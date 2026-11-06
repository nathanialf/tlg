/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x270. */
static void cleanupLoadedObjecthkUFloat8(void *object) /* derived name */
{
    static_cast<hkUFloat8 *>(object)->~hkUFloat8();
}

/* This file's static initializer (0x1500): hkUFloat8's reflection (hkClass
 * 0x57b7620: no parent, its one member, value, from the record at
 * 0x168c600), then its type info (no finish callback, no vtable). */
const hkClass D_57b7620("hkUFloat8", 0, sizeof(hkUFloat8), 0, 0, 0, 0, D_168c600, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57b7670;
const hkTypeInfo D_57b7670("hkUFloat8", "!hkUFloat8", 0, cleanupLoadedObjecthkUFloat8, 0,
                           sizeof(hkUFloat8));

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x270. */
static void cleanupLoadedObjecthkFloat16Transform(void *object) /* derived name */
{
    static_cast<hkFloat16Transform *>(object)->~hkFloat16Transform();
}

/* This file's static initializer (0xce0): hkFloat16Transform's
 * reflection, no parent and its one member, then its type info (no finish
 * callback, no vtable). */
const hkClass D_57af6e8("hkFloat16Transform", 0, sizeof(hkFloat16Transform), 0, 0, 0, 0, D_168c370,
                        1, 0, 0, 0, 0);
extern const hkTypeInfo D_57af738;
const hkTypeInfo D_57af738("hkFloat16Transform", "!hkFloat16Transform", 0,
                           cleanupLoadedObjecthkFloat16Transform, 0, sizeof(hkFloat16Transform));

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x270. */
static void cleanupLoadedObjecthkMultiThreadCheck(void *object) /* derived name */
{
    static_cast<hkMultiThreadCheck *>(object)->~hkMultiThreadCheck();
}

/* This file's static initializer (0x1420): hkMultiThreadCheck's reflection
 * (hkClass 0x57b75a0: no parent, its two enums and four members), then its
 * type info (no finish callback, no vtable). */
const hkClass D_57b75a0("hkMultiThreadCheck", 0, sizeof(hkMultiThreadCheck), 0, 0, D_168c5b0, 2,
                        D_168c4c0, 4, 0, 0, 0, 0);
extern const hkTypeInfo D_57b75f0;
const hkTypeInfo D_57b75f0("hkMultiThreadCheck", "!hkMultiThreadCheck", 0,
                           cleanupLoadedObjecthkMultiThreadCheck, 0, sizeof(hkMultiThreadCheck));

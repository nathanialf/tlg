/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x270. */
static void cleanupLoadedObjecthkSphere(void *object) /* derived name */
{
    static_cast<hkSphere *>(object)->~hkSphere();
}

/* This file's static initializer (0x1080): hkSphere's reflection, no
 * parent and its one member, then its type info (no finish callback, no
 * vtable). */
const hkClass D_57af790("hkSphere", 0, sizeof(hkSphere), 0, 0, 0, 0, D_168c3e0, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57af7e0;
const hkTypeInfo D_57af7e0("hkSphere", "!hkSphere", 0, cleanupLoadedObjecthkSphere, 0,
                           sizeof(hkSphere));

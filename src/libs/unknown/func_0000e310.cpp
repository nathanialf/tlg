/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0xdbc0. */
static void cleanupLoadedObjecthkContactPoint(void *object) /* derived name */
{
    static_cast<hkContactPoint *>(object)->~hkContactPoint();
}

/* This file's static initializer (0xe310): hkContactPoint's reflection, no
 * parent and its two members, then its type info (no finish callback, no
 * vtable). */
const hkClass D_57b8710("hkContactPoint", 0, sizeof(hkContactPoint), 0, 0, 0, 0, D_168d9b0, 2, 0, 0,
                        0, 0);
extern const hkTypeInfo D_57b8760;
const hkTypeInfo D_57b8760("hkContactPoint", "!hkContactPoint", 0,
                           cleanupLoadedObjecthkContactPoint, 0, sizeof(hkContactPoint));

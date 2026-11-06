/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x396a0. */
static void cleanupLoadedObjecthknpBody(void *object) /* derived name */
{
    static_cast<hknpBody *>(object)->~hknpBody();
}

/* This file's static initializer (0x3ac80): hknpBody's reflection (hkClass
 * 0x57bfa50: no parent, its one enum and twenty members, version 2), then
 * its type info (no finish callback, no vtable). */
const hkClass D_57bfa50("hknpBody", 0, sizeof(hknpBody), 0, 0, D_16956b0, 1, D_1695350, 20, 0, 0, 0,
                        2);
extern const hkTypeInfo D_57bfaa0;
const hkTypeInfo D_57bfaa0("hknpBody", "!hknpBody", 0, cleanupLoadedObjecthknpBody, 0,
                           sizeof(hknpBody));

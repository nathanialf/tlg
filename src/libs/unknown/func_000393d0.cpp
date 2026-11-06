/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x1c1e0. */
static void cleanupLoadedObjecthknpMotion(void *object) /* derived name */
{
    static_cast<hknpMotion *>(object)->~hknpMotion();
}

/* This file's static initializer (0x393d0): hknpMotion's reflection, no parent
 * and its members, then its type info (no finish callback, no vtable). */
const hkClass D_57bf3c0("hknpMotion", 0, sizeof(hknpMotion), 0, 0, 0, 0, D_16945d0, 16, 0, 0, 0, 3);
extern const hkTypeInfo D_57bf410;
const hkTypeInfo D_57bf410("hknpMotion", "!hknpMotion", 0, cleanupLoadedObjecthknpMotion, 0,
                           sizeof(hknpMotion));

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0xe5c0. */
static void cleanupLoadedObjecthkSweptTransformf(void *object) /* derived name */
{
    static_cast<hkSweptTransformf *>(object)->~hkSweptTransformf();
}

/* This file's static initializer (0x14990): hkSweptTransformf's reflection, no parent
 * and its members, then its type info (no finish callback, no vtable). */
const hkClass D_57b94e0("hkSweptTransformf", 0, sizeof(hkSweptTransformf), 0, 0, 0, 0, D_168e4e0, 5,
                        0, 0, 0, 0);
extern const hkTypeInfo D_57b9530;
const hkTypeInfo D_57b9530("hkSweptTransformf", "!hkSweptTransformf", 0,
                           cleanupLoadedObjecthkSweptTransformf, 0, sizeof(hkSweptTransformf));

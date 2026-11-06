/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x6c80. */
static void finishLoadedObjecthkQTransformf(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkQTransformf(flag);
}

static void cleanupLoadedObjecthkQTransformf(void *object) /* derived name */
{
    static_cast<hkQTransformf *>(object)->~hkQTransformf();
}

/* This file's static initializer (0x8c80): hkQTransformf's reflection
 * (hkClass 0x57b7f68: no parent, its two members), then its type info (no
 * vtable). */
const hkClass D_57b7f68("hkQTransformf", 0, sizeof(hkQTransformf), 0, 0, 0, 0, D_168d1c0, 2, 0, 0,
                        0, 0);
extern const hkTypeInfo D_57b7fb8;
const hkTypeInfo D_57b7fb8("hkQTransformf", "!hkQTransformf", finishLoadedObjecthkQTransformf,
                           cleanupLoadedObjecthkQTransformf, 0, sizeof(hkQTransformf));

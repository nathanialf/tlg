/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0xe5c0. */
static void finishLoadedObjecthkQTransform(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkQTransform(flag);
}

static void cleanupLoadedObjecthkQTransform(void *object) /* derived name */
{
    static_cast<hkQTransform *>(object)->~hkQTransform();
}

/* This file's static initializer (0x17d40): hkQTransform's reflection
 * (hkClass 0x57b99f0: hkQTransformf's as the parent, no members, version
 * 2), then its type info (no vtable). */
const hkClass D_57b99f0("hkQTransform", &D_57b7f68, sizeof(hkQTransform), 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        2);
extern const hkTypeInfo D_57b9a40;
const hkTypeInfo D_57b9a40("hkQTransform", "!hkQTransform", finishLoadedObjecthkQTransform,
                           cleanupLoadedObjecthkQTransform, 0, sizeof(hkQTransform));

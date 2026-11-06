/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x1c1e0. */
static void finishLoadedObjecthkMassProperties(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkMassProperties(flag);
}

static void cleanupLoadedObjecthkMassProperties(void *object) /* derived name */
{
    static_cast<hkMassProperties *>(object)->~hkMassProperties();
}

/* This file's static initializer (0x23c10): hkMassProperties's reflection
 * (hkClass 0x57bcfa0: no parent, its four members, version 1), then its
 * type info (no vtable). */
const hkClass D_57bcfa0("hkMassProperties", 0, sizeof(hkMassProperties), 0, 0, 0, 0, D_1691b50, 4,
                        0, 0, 0, 1);
extern const hkTypeInfo D_57bcff0;
const hkTypeInfo D_57bcff0("hkMassProperties", "!hkMassProperties",
                           finishLoadedObjecthkMassProperties, cleanupLoadedObjecthkMassProperties,
                           0, sizeof(hkMassProperties));

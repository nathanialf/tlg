/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): nothing to finish, nothing to clean up; the linker folded them all
 * into the empty body 0x270. */
static void finishLoadedObjecthkSimpleProperty(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkSimpleProperty(flag);
}

static void cleanupLoadedObjecthkSimpleProperty(void *object)
{
    static_cast<hkSimpleProperty *>(object)->~hkSimpleProperty();
}

static void cleanupLoadedObjecthkSimplePropertyValue(void *object)
{
    static_cast<hkSimplePropertyValue *>(object)->~hkSimplePropertyValue();
}

/* This file's static initializer (0x12a0): hkSimpleProperty's reflection
 * (no parent, its three members, version 2) and type info with its
 * finish callback, then hkSimplePropertyValue's (its one member, version
 * 1), neither with a vtable. The type infos' names are the base's
 * strings. */
const hkClass D_57b74a0("hkSimpleProperty", 0, sizeof(hkSimpleProperty), 0, 0, 0, 0, D_168c410, 3,
                        0, 0, 0, 2);
extern const hkTypeInfo D_57b74f0;
const hkTypeInfo D_57b74f0("hkSimpleProperty", "!hkSimpleProperty",
                           finishLoadedObjecthkSimpleProperty, cleanupLoadedObjecthkSimpleProperty,
                           0, sizeof(hkSimpleProperty));
const hkClass D_57b7520("hkSimplePropertyValue", 0, sizeof(hkSimplePropertyValue), 0, 0, 0, 0,
                        D_168c490, 1, 0, 0, 0, 1);
extern const hkTypeInfo D_57b7570;
const hkTypeInfo D_57b7570("hkSimplePropertyValue", "!hkSimplePropertyValue", 0,
                           cleanupLoadedObjecthkSimplePropertyValue, 0,
                           sizeof(hkSimplePropertyValue));

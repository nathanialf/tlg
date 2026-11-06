/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkxAttribute's type info (0x57c7900):
 * construct the object in place from a loaded image through its
 * out-of-line finish constructor. */
static void finishLoadedObjecthkxAttribute(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_0017d790(static_cast<hkxAttribute *>(object), flag);
}

static void cleanupLoadedObjecthkxAttribute(void *object) /* derived name */
{
    static_cast<hkxAttribute *>(object)->~hkxAttribute();
}

/* This file's static initializer (0x8b890): hkxAttribute's reflection, no
 * parent, its one enum and two members, version 1, then its type info (the
 * finish callback FUN_0008b870, no vtable). */
const hkClass D_57c78b0("hkxAttribute", 0, sizeof(hkxAttribute), 0, 0, D_16a2490, 1, D_16a23e0, 2,
                        0, 0, 0, 1);
extern const hkTypeInfo D_57c7900;
const hkTypeInfo D_57c7900("hkxAttribute", "!hkxAttribute", finishLoadedObjecthkxAttribute,
                           cleanupLoadedObjecthkxAttribute, 0, sizeof(hkxAttribute));

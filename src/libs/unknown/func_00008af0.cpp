/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): nothing to clean up in either class; the linker folded both into
 * the empty body 0x6c80. */
static void cleanupLoadedObjecthkCustomAttributesAttribute(void *object)
{
    static_cast<hkCustomAttributes::Attribute *>(object)->~Attribute();
}

static void cleanupLoadedObjecthkCustomAttributes(void *object)
{
    static_cast<hkCustomAttributes *>(object)->~hkCustomAttributes();
}

/* This file's static initializer (0x8af0): hkCustomAttributes::Attribute's
 * reflection (no parent, its two members) and type info, then
 * hkCustomAttributes's (its one member), neither with a finish callback or
 * a vtable. The type infos' names are the base's strings. */
const hkClass D_57b7e68("hkCustomAttributesAttribute", 0, sizeof(hkCustomAttributes::Attribute), 0,
                        0, 0, 0, D_168d140, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57b7eb8;
const hkTypeInfo D_57b7eb8("hkCustomAttributesAttribute", "!hkCustomAttributes::Attribute", 0,
                           cleanupLoadedObjecthkCustomAttributesAttribute, 0,
                           sizeof(hkCustomAttributes::Attribute));
const hkClass D_57b7ee8("hkCustomAttributes", 0, sizeof(hkCustomAttributes), 0, 0, 0, 0, D_168d190,
                        1, 0, 0, 0, 0);
extern const hkTypeInfo D_57b7f38;
const hkTypeInfo D_57b7f38("hkCustomAttributes", "!hkCustomAttributes", 0,
                           cleanupLoadedObjecthkCustomAttributes, 0, sizeof(hkCustomAttributes));

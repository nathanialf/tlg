/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x6c80. */
static void cleanupLoadedObjecthkContactPointMaterial(void *object) /* derived name */
{
    static_cast<hkContactPointMaterial *>(object)->~hkContactPointMaterial();
}

/* hkContactPointMaterial's members' defaults, file-local (D17); the rows are
 * written at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
static const hkContactPointMaterialDefaults D_14b31d0[1] = {
#include "gen/D_14b31d0.inc"
};

/* This file's static initializer (0x8000): hkContactPointMaterial's
 * reflection (hkClass 0x57b7d98: no parent, its one enum, five members and
 * their defaults, version 1), then its type info (no finish callback, no
 * vtable). */
const hkClass D_57b7d98("hkContactPointMaterial", 0, sizeof(hkContactPointMaterial), 0, 0,
                        D_168d0d0, 1, D_168cfc0, 5, D_14b31d0, 0, 0, 1);
extern const hkTypeInfo D_57b7de8;
const hkTypeInfo D_57b7de8("hkContactPointMaterial", "!hkContactPointMaterial", 0,
                           cleanupLoadedObjecthkContactPointMaterial, 0,
                           sizeof(hkContactPointMaterial));

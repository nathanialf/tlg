/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkContactPointMaterial's loaded-object cleanup: nothing to clean up (the
 * linker folded it into the empty body 0x6c80, FUN_00006c80). */
void FUN_00006c80(void *object) {}

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
const hkTypeInfo D_57b7de8("hkContactPointMaterial", "!hkContactPointMaterial", 0, FUN_00006c80, 0,
                           sizeof(hkContactPointMaterial));

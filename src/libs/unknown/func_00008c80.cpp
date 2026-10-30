/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkQTransformf's loaded-object callbacks: nothing to finish, nothing to
 * clean up (the linker folded both into the empty body 0x6c80). */
void FUN_00006c80(void *object, int finishing) {}

void FUN_00006c80(void *object) {}

/* This file's static initializer (0x8c80): hkQTransformf's reflection
 * (hkClass 0x57b7f68: no parent, its two members), then its type info (no
 * vtable). */
const hkClass D_57b7f68("hkQTransformf", 0, sizeof(hkQTransformf), 0, 0, 0, 0, D_168d1c0, 2, 0, 0,
                        0, 0);
extern const hkTypeInfo D_57b7fb8;
const hkTypeInfo D_57b7fb8("hkQTransformf", "!hkQTransformf", FUN_00006c80, FUN_00006c80, 0,
                           sizeof(hkQTransformf));

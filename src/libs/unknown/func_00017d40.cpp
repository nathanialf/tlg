/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkQTransform's loaded-object callbacks: nothing to finish, nothing to
 * clean up (the linker folded both into the empty body 0xe5c0). */
void FUN_0000e5c0(void *object, int finishing) {}

void FUN_0000e5c0(void *object) {}

/* This file's static initializer (0x17d40): hkQTransform's reflection
 * (hkClass 0x57b99f0: hkQTransformf's as the parent, no members, version
 * 2), then its type info (no vtable). */
const hkClass D_57b99f0("hkQTransform", &D_57b7f68, sizeof(hkQTransform), 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        2);
extern const hkTypeInfo D_57b9a40;
const hkTypeInfo D_57b9a40("hkQTransform", "!hkQTransform", FUN_0000e5c0, FUN_0000e5c0, 0,
                           sizeof(hkQTransform));

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkMassProperties's loaded-object callbacks: nothing to finish, nothing to
 * clean up (the linker folded both into the empty body 0x1c1e0). */
void FUN_0001c1e0(void *object, int finishing) {}

void FUN_0001c1e0(void *object) {}

/* This file's static initializer (0x23c10): hkMassProperties's reflection
 * (hkClass 0x57bcfa0: no parent, its four members, version 1), then its
 * type info (no vtable). */
const hkClass D_57bcfa0("hkMassProperties", 0, sizeof(hkMassProperties), 0, 0, 0, 0, D_1691b50, 4,
                        0, 0, 0, 1);
extern const hkTypeInfo D_57bcff0;
const hkTypeInfo D_57bcff0("hkMassProperties", "!hkMassProperties", FUN_0001c1e0, FUN_0001c1e0, 0,
                           sizeof(hkMassProperties));

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkCompressedMassProperties's loaded-object cleanup: nothing to clean up (the linker folded it
 * into the empty body 0x1c1e0, FUN_0001c1e0). */
void FUN_0001c1e0(void *object) {}

/* This file's static initializer (0x22a90): hkCompressedMassProperties's reflection, no parent
 * and its members, then its type info (no finish callback, no vtable). */
const hkClass D_57bc9e0("hkCompressedMassProperties", 0, sizeof(hkCompressedMassProperties), 0, 0,
                        0, 0, D_1691090, 5, 0, 0, 0, 0);
extern const hkTypeInfo D_57bca30;
const hkTypeInfo D_57bca30("hkCompressedMassProperties", "!hkCompressedMassProperties", 0,
                           FUN_0001c1e0, 0, sizeof(hkCompressedMassProperties));

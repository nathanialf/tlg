/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpMotion's loaded-object cleanup: nothing to clean up (the linker folded it
 * into the empty body 0x1c1e0, FUN_0001c1e0). */
void FUN_0001c1e0(void *object) {}

/* This file's static initializer (0x393d0): hknpMotion's reflection, no parent
 * and its members, then its type info (no finish callback, no vtable). */
const hkClass D_57bf3c0("hknpMotion", 0, sizeof(hknpMotion), 0, 0, 0, 0, D_16945d0, 16, 0, 0, 0, 3);
extern const hkTypeInfo D_57bf410;
const hkTypeInfo D_57bf410("hknpMotion", "!hknpMotion", 0, FUN_0001c1e0, 0, sizeof(hknpMotion));

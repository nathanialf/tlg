/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpBody's loaded-object cleanup: nothing to clean up (the linker folded
 * it into the shared empty body 0x396a0, FUN_000396a0). */
void FUN_000396a0(void *object) {}

/* This file's static initializer (0x3ac80): hknpBody's reflection (hkClass
 * 0x57bfa50: no parent, its one enum and twenty members, version 2), then
 * its type info (no finish callback, no vtable). */
const hkClass D_57bfa50("hknpBody", 0, sizeof(hknpBody), 0, 0, D_16956b0, 1, D_1695350, 20, 0, 0, 0,
                        2);
extern const hkTypeInfo D_57bfaa0;
const hkTypeInfo D_57bfaa0("hknpBody", "!hknpBody", 0, FUN_000396a0, 0, sizeof(hknpBody));

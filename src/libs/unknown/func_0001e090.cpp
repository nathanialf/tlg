/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkcdFourAabb's loaded-object callbacks: nothing to finish, nothing to
 * clean up (the linker folded both into the empty body 0x1c1e0). */
void FUN_0001c1e0(void *object, int finishing) {}

void FUN_0001c1e0(void *object) {}

/* This file's static initializer (0x1e090): hkcdFourAabb's reflection
 * (hkClass 0x57ba890: no parent, its one enum and six members), then its
 * type info (no vtable). */
const hkClass D_57ba890("hkcdFourAabb", 0, sizeof(hkcdFourAabb), 0, 0, D_168fdb0, 1, D_168fc60, 6,
                        0, 0, 0, 0);
extern const hkTypeInfo D_57ba8e0;
const hkTypeInfo D_57ba8e0("hkcdFourAabb", "!hkcdFourAabb", FUN_0001c1e0, FUN_0001c1e0, 0,
                           sizeof(hkcdFourAabb));

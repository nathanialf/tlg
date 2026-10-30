/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkcdAdf's finish callback: nothing to finish (the linker folded it into
 * the shared empty body 0x1c1e0, FUN_0001c1e0). */
void FUN_0001c1e0(void *object, int finishing) {}

/* This file's static initializer (0x1f260): hkcdAdf's reflection (hkClass
 * 0x57bb290: no parent, its seven members), then its type info (the
 * cleanup callback 0x1f1e0, no vtable). */
const hkClass D_57bb290("hkcdAdf", 0, sizeof(hkcdAdf), 0, 0, 0, 0, D_16900c0, 7, 0, 0, 0, 0);
extern const hkTypeInfo D_57bb2e0;
const hkTypeInfo D_57bb2e0("hkcdAdf", "!hkcdAdf", FUN_0001c1e0, hkcdAdf::FUN_0001f1e0, 0,
                           sizeof(hkcdAdf));

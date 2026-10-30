/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkAabb16's loaded-object cleanup: nothing to clean up (the linker folded it
 * into the empty body 0xe5c0, FUN_0000e5c0). */
void FUN_0000e5c0(void *object) {}

/* This file's static initializer (0x136c0): hkAabb16's reflection, no parent
 * and its members, then its type info (no finish callback, no vtable). */
const hkClass D_57b9460("hkAabb16", 0, sizeof(hkAabb16), 0, 0, 0, 0, D_168e3c0, 4, 0, 0, 0, 0);
extern const hkTypeInfo D_57b94b0;
const hkTypeInfo D_57b94b0("hkAabb16", "!hkAabb16", 0, FUN_0000e5c0, 0, sizeof(hkAabb16));

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkAabbHalf's loaded-object cleanup: nothing to clean up (the linker
 * folded it into the empty body 0xe5c0, FUN_0000e5c0). */
void FUN_0000e5c0(void *object) {}

/* This file's static initializer (0x11390): hkAabbHalf's reflection, no
 * parent, its one member, version 1, then its type info (no finish
 * callback, no vtable). */
const hkClass D_57b9238("hkAabbHalf", 0, sizeof(hkAabbHalf), 0, 0, 0, 0, D_168e150, 1, 0, 0, 0, 1);
extern const hkTypeInfo D_57b9288;
const hkTypeInfo D_57b9288("hkAabbHalf", "!hkAabbHalf", 0, FUN_0000e5c0, 0, sizeof(hkAabbHalf));

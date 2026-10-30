/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkSphere's loaded-object cleanup: nothing to clean up (the linker folded
 * it into the shared empty body 0x270, FUN_00000270). */
void FUN_00000270(void *object) {}

/* This file's static initializer (0x1080): hkSphere's reflection, no
 * parent and its one member, then its type info (no finish callback, no
 * vtable). */
const hkClass D_57af790("hkSphere", 0, sizeof(hkSphere), 0, 0, 0, 0, D_168c3e0, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57af7e0;
const hkTypeInfo D_57af7e0("hkSphere", "!hkSphere", 0, FUN_00000270, 0, sizeof(hkSphere));

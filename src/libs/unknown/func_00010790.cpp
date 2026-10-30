/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkMotionState's loaded-object cleanup: nothing to clean up (the linker
 * folded it into the empty body 0xe5c0, FUN_0000e5c0). */
void FUN_0000e5c0(void *object) {}

/* This file's static initializer (0x10790): hkMotionState's reflection, no
 * parent, its ten members, version 3, then its type info (no finish
 * callback, no vtable). */
const hkClass D_57b9138("hkMotionState", 0, sizeof(hkMotionState), 0, 0, 0, 0, D_168df50, 10, 0, 0,
                        0, 3);
extern const hkTypeInfo D_57b9188;
const hkTypeInfo D_57b9188("hkMotionState", "!hkMotionState", 0, FUN_0000e5c0, 0,
                           sizeof(hkMotionState));

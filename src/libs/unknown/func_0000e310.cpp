/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkContactPoint's loaded-object cleanup: nothing to clean up (the linker
 * folded it into the empty body 0xdbc0, FUN_0000dbc0). */
void FUN_0000dbc0(void *object) {}

/* This file's static initializer (0xe310): hkContactPoint's reflection, no
 * parent and its two members, then its type info (no finish callback, no
 * vtable). */
const hkClass D_57b8710("hkContactPoint", 0, sizeof(hkContactPoint), 0, 0, 0, 0, D_168d9b0, 2, 0, 0,
                        0, 0);
extern const hkTypeInfo D_57b8760;
const hkTypeInfo D_57b8760("hkContactPoint", "!hkContactPoint", 0, FUN_0000dbc0, 0,
                           sizeof(hkContactPoint));

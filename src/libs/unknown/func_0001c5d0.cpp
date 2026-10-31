/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The boxes' loaded-object cleanups: nothing to clean up in either class.
 * Each registration passes its class's own callback; the linker folded
 * both into the empty body 0x1c1e0, so the first is spelled under the
 * address's own name (D15's round 57 addendum) and the second under that
 * name with its class appended (D15's round 68A addendum). */
void FUN_0001c1e0(void *object) {}

void FUN_0001c1e0_hkAabbUint32(void *object) {}

/* This file's static initializer (0x1c5d0): hkAabb's reflection (no
 * parent, its two members) and type info, then hkAabbUint32's (its six
 * members), neither with a finish callback or a vtable. The type infos'
 * names are the base's strings. */
const hkClass D_57b9c20("hkAabb", 0, sizeof(hkAabb), 0, 0, 0, 0, D_168eb70, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57b9c70;
const hkTypeInfo D_57b9c70("hkAabb", "!hkAabb", 0, FUN_0001c1e0, 0, sizeof(hkAabb));
const hkClass D_57b9ca0("hkAabbUint32", 0, sizeof(hkAabbUint32), 0, 0, 0, 0, D_168ebc0, 6, 0, 0, 0,
                        0);
extern const hkTypeInfo D_57b9cf0;
const hkTypeInfo D_57b9cf0("hkAabbUint32", "!hkAabbUint32", 0, FUN_0001c1e0_hkAabbUint32, 0,
                           sizeof(hkAabbUint32));

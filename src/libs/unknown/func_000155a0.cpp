/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The packed vectors' loaded-object cleanups: nothing to clean up in
 * either class. Each registration passes its class's own callback; the
 * linker folded both into the empty body 0xe5c0, so the first is spelled
 * under the address's own name (D15's round 57 addendum) and the second
 * under that name with its class appended (D15's round 68A addendum). */
void FUN_0000e5c0(void *object) {}

void FUN_0000e5c0_hkPackedVector8_3(void *object) {}

/* This file's static initializer (0x155a0): hkPackedVector3's reflection
 * (no parent, its one member) and type info, then hkPackedVector8_3's,
 * neither with a finish callback or a vtable. The type infos' names are
 * the base's strings. */
const hkClass D_57b98e0("hkPackedVector3", 0, sizeof(hkPackedVector3), 0, 0, 0, 0, D_168e770, 1, 0,
                        0, 0, 0);
extern const hkTypeInfo D_57b9930;
const hkTypeInfo D_57b9930("hkPackedVector3", "!hkPackedVector3", 0, FUN_0000e5c0, 0,
                           sizeof(hkPackedVector3));
const hkClass D_57b9960("hkPackedVector8_3", 0, sizeof(hkPackedVector8_3), 0, 0, 0, 0, D_168e7a0, 1,
                        0, 0, 0, 0);
extern const hkTypeInfo D_57b99b0;
const hkTypeInfo D_57b99b0("hkPackedVector8_3", "!hkPackedVector8_3", 0,
                           FUN_0000e5c0_hkPackedVector8_3, 0, sizeof(hkPackedVector8_3));

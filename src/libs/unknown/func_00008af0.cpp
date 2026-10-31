/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The custom attributes' loaded-object cleanups: nothing to clean up in
 * either class. Each registration passes its class's own callback, as the
 * reflection files register them; the linker folded both into the empty
 * body 0x6c80, so the first is spelled under the address's own name (D15's
 * round 57 addendum) and the second under that name with its class
 * appended (D15's round 68A addendum). One function per registration keeps
 * the address formed before each hkClass call, as the base holds it; one
 * shared callback would keep its load in a register across the call. */
void FUN_00006c80(void *object) {}

void FUN_00006c80_hkCustomAttributes(void *object) {}

/* This file's static initializer (0x8af0): hkCustomAttributes::Attribute's
 * reflection (no parent, its two members) and type info, then
 * hkCustomAttributes's (its one member), neither with a finish callback or
 * a vtable. The type infos' names are the base's strings. */
const hkClass D_57b7e68("hkCustomAttributesAttribute", 0, sizeof(hkCustomAttributes::Attribute), 0,
                        0, 0, 0, D_168d140, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57b7eb8;
const hkTypeInfo D_57b7eb8("hkCustomAttributesAttribute", "!hkCustomAttributes::Attribute", 0,
                           FUN_00006c80, 0, sizeof(hkCustomAttributes::Attribute));
const hkClass D_57b7ee8("hkCustomAttributes", 0, sizeof(hkCustomAttributes), 0, 0, 0, 0, D_168d190,
                        1, 0, 0, 0, 0);
extern const hkTypeInfo D_57b7f38;
const hkTypeInfo D_57b7f38("hkCustomAttributes", "!hkCustomAttributes", 0,
                           FUN_00006c80_hkCustomAttributes, 0, sizeof(hkCustomAttributes));

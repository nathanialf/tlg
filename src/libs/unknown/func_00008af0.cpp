/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The custom attributes' loaded-object cleanup: nothing to clean up (the
 * linker folded it into the empty body 0x6c80, spelled under the address's
 * own name as hkQTransformf's file spells it, D15's round 57 addendum). */
void FUN_00006c80(void *object) {}

// NONMATCHING: the first cleanup's address is kept in r14 across the second
// hkClass call (one GOT load CSE'd), where the base forms it twice, before and
// after the call (`lea rdx, [rip - 0x1f0d]`, `lea rax, [rip - 0x1f8a]`): two
// distinct external callbacks, each class's own, give every instruction
// (diagnostic; D15 names the folded body 0x6c80 once, a ruling is asked).
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
const hkTypeInfo D_57b7f38("hkCustomAttributes", "!hkCustomAttributes", 0, FUN_00006c80, 0,
                           sizeof(hkCustomAttributes));

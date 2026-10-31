/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The simple properties' loaded-object callbacks: nothing to finish,
 * nothing to clean up. Each registration passes its class's own
 * callbacks; the linker folded them all into the empty body 0x270, so
 * the first class's are spelled under the address's own name (D15's
 * round 57 addendum) and the second's cleanup under that name with its
 * class appended (D15's round 68A addendum). */
void FUN_00000270(void *object, int finishing) {}

void FUN_00000270(void *object) {}

void FUN_00000270_hkSimplePropertyValue(void *object) {}

/* This file's static initializer (0x12a0): hkSimpleProperty's reflection
 * (no parent, its three members, version 2) and type info with its
 * finish callback, then hkSimplePropertyValue's (its one member, version
 * 1), neither with a vtable. The type infos' names are the base's
 * strings. */
const hkClass D_57b74a0("hkSimpleProperty", 0, sizeof(hkSimpleProperty), 0, 0, 0, 0, D_168c410, 3,
                        0, 0, 0, 2);
extern const hkTypeInfo D_57b74f0;
const hkTypeInfo D_57b74f0("hkSimpleProperty", "!hkSimpleProperty", FUN_00000270, FUN_00000270, 0,
                           sizeof(hkSimpleProperty));
const hkClass D_57b7520("hkSimplePropertyValue", 0, sizeof(hkSimplePropertyValue), 0, 0, 0, 0,
                        D_168c490, 1, 0, 0, 0, 1);
extern const hkTypeInfo D_57b7570;
const hkTypeInfo D_57b7570("hkSimplePropertyValue", "!hkSimplePropertyValue", 0,
                           FUN_00000270_hkSimplePropertyValue, 0, sizeof(hkSimplePropertyValue));

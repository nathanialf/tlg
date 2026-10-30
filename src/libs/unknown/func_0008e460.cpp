/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkPackfileSectionHeader's loaded-object cleanup: nothing to clean up.
 * The linker folded it into the empty body 0x8c0a0, whose row is
 * hkxVertexDescription's finish constructor: spelled under the address's
 * own name as hkPackfileHeader's (0x8e380) is (docs/DECISIONS.md D15, the
 * round 57 addendum). */
void FUN_0008c0a0(void *object) {}

/* This file's static initializer (0x8e460): hkPackfileSectionHeader's reflection, no parent,
 * its members, version 1, then its type info (no finish callback, no
 * vtable). */
const hkClass D_57c8330("hkPackfileSectionHeader", 0, sizeof(hkPackfileSectionHeader), 0, 0, 0, 0,
                        D_16a2dd0, 10, 0, 0, 0, 1);
extern const hkTypeInfo D_57c8380;
const hkTypeInfo D_57c8380("hkPackfileSectionHeader", "!hkPackfileSectionHeader", 0, FUN_0008c0a0,
                           0, sizeof(hkPackfileSectionHeader));

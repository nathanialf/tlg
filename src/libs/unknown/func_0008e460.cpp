/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkPackfileSectionHeader's loaded-object cleanup: nothing to clean up. The linker folded it
 * into the empty body 0x8c0a0, whose row is hkxVertexDescription's finish
 * constructor: no overload of a constructor's name exists to spell it, so
 * the name here waits for a ruling and the function is not claimed
 * (docs/NOTES.md, Round 57); quick_diff finds it equal. */
void FUN_0008c0a0(void *object) {}

/* This file's static initializer (0x8e460): hkPackfileSectionHeader's reflection, no parent,
 * its members, version 1, then its type info (no finish callback, no
 * vtable). */
const hkClass D_57c8330("hkPackfileSectionHeader", 0, sizeof(hkPackfileSectionHeader), 0, 0, 0, 0,
                        D_16a2dd0, 10, 0, 0, 0, 1);
extern const hkTypeInfo D_57c8380;
const hkTypeInfo D_57c8380("hkPackfileSectionHeader", "!hkPackfileSectionHeader", 0, FUN_0008c0a0,
                           0, sizeof(hkPackfileSectionHeader));

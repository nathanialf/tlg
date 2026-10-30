/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkPackfileHeader's loaded-object cleanup: nothing to clean up. The linker folded it
 * into the empty body 0x8c0a0, whose row is hkxVertexDescription's finish
 * constructor: no overload of a constructor's name exists to spell it, so
 * the name here waits for a ruling and the function is not claimed
 * (docs/NOTES.md, Round 57); quick_diff finds it equal. */
void FUN_0008c0a0(void *object) {}

/* This file's static initializer (0x8e380): hkPackfileHeader's reflection, no parent,
 * its members, version 2, then its type info (no finish callback, no
 * vtable). */
const hkClass D_57c82b0("hkPackfileHeader", 0, sizeof(hkPackfileHeader), 0, 0, 0, 0, D_16a2bc0, 13,
                        0, 0, 0, 2);
extern const hkTypeInfo D_57c8300;
const hkTypeInfo D_57c8300("hkPackfileHeader", "!hkPackfileHeader", 0, FUN_0008c0a0, 0,
                           sizeof(hkPackfileHeader));

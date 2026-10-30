/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkColor (the class name, the string at 0x14b35c0): no members, one
 * byte. */
struct hkColor {};

/* hkColor's loaded-object cleanup: nothing to clean up. The linker folded
 * it into the empty body 0x8d60, whose row is AllocatorBase's destructor:
 * the 0x6a60 spelling (an overload of the folded body's name) has no form
 * for a destructor's name, so the name here waits for a ruling and the
 * function is not claimed (docs/NOTES.md, Round 57); quick_diff finds it
 * equal. */
void FUN_00008d60(void *object) {}

/* This file's static initializer (0xa1d0): hkColor's reflection, no
 * parent and no members, then its type info (no finish callback, no
 * vtable). */
const hkClass D_57b83f0("hkColor", 0, sizeof(hkColor), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
extern const hkTypeInfo D_57b8440;
const hkTypeInfo D_57b8440("hkColor", "!hkColor", 0, FUN_00008d60, 0, sizeof(hkColor));

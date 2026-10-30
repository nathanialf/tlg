/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkFourTransposedPointsf's loaded-object cleanup: nothing to clean up.
 * The linker folded it into the empty body 0x8d60, whose row is
 * AllocatorBase's destructor: as for hkColor's (0xa1d0) the name here waits
 * for a ruling and the function is not claimed (docs/NOTES.md, Round 57);
 * quick_diff finds it equal. */
void FUN_00008d60(void *object) {}

/* This file's static initializer (0xc1b0): hkFourTransposedPointsf's
 * reflection, no parent and its one member, then its type info (no finish
 * callback, no vtable). */
const hkClass D_57b8488("hkFourTransposedPointsf", 0, sizeof(hkFourTransposedPointsf), 0, 0, 0, 0,
                        D_168d650, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57b84d8;
const hkTypeInfo D_57b84d8("hkFourTransposedPointsf", "!hkFourTransposedPointsf", 0, FUN_00008d60,
                           0, sizeof(hkFourTransposedPointsf));

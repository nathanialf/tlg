/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkColor (the class name, the string at 0x14b35c0): no members, one
 * byte. */
struct hkColor {};

/* hkColor's loaded-object cleanup: nothing to clean up. The linker folded
 * it into the empty body 0x8d60, whose row is AllocatorBase's destructor,
 * a name that admits no overload with the callback's signature: the
 * callback is spelled under the address's own name, FUN_00008d60, with
 * external linkage, and the gate places it at the type info's field
 * (docs/DECISIONS.md D15, the round 57 addendum). */
void FUN_00008d60(void *object) {}

/* This file's static initializer (0xa1d0): hkColor's reflection, no
 * parent and no members, then its type info (no finish callback, no
 * vtable). */
const hkClass D_57b83f0("hkColor", 0, sizeof(hkColor), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
extern const hkTypeInfo D_57b8440;
const hkTypeInfo D_57b8440("hkColor", "!hkColor", 0, FUN_00008d60, 0, sizeof(hkColor));

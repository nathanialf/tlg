/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 0 of its vtable (0x1695b10): nothing of its own to destroy, so its
 * vtable is not stored; the wrapped data's destructor follows inline. The
 * class's key function: the deleting destructor (0x3c170) is emitted with
 * it. */
hknpBreakableConstraintData::~hknpBreakableConstraintData() {}

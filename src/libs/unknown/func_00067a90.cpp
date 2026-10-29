/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 0 of its vtable (0x1699a90), and of hkpWrappedConstraintData's
 * (0x169cee0): nothing of its own to destroy, the wrapped data's
 * destructor inline. The class's key function: the deleting destructor
 * (0x679f0) is emitted with it. */
hknpMalleableConstraintData::~hknpMalleableConstraintData() {}

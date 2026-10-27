/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* AllocatorBase's destructor: nothing to destroy (D15: the one name of the
 * empty body at 0x8d60; the vtable slots that hold it resolve by address). */
AllocatorBase::~AllocatorBase() {}

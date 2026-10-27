/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Nothing to destroy; the deleting destructor (0x3a350, slot 1 of the vtable
 * 0x16952a0 and of two other 0xa0-byte classes') is the one emitted with
 * it. */
hknpGroupCollisionFilter::~hknpGroupCollisionFilter() {}

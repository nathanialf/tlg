/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Nothing to destroy; the deleting destructor (0x8a210, slot 1 of the vtable
 * 0x16a1a70 and of hkxLight's and one other 0x50-byte class's) is the one
 * emitted with it. */
hkxCamera::~hkxCamera() {}

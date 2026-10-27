/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Nothing to destroy; the deleting destructor (0x16d040, slot 1 of the
 * vtable 0x16a55b0) frees the collector's 0x60 bytes. */
hknpScaledOffsetQueryCollector::~hknpScaledOffsetQueryCollector() {}

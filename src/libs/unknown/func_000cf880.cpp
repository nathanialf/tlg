/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Nothing to destroy; the deleting destructor (0xcf880, slot 1 of the
 * vtables 0x16a3c40 and 0x16a3cf0) frees the collector's 0x50 bytes. */
hknpScaledQueryCollector::~hknpScaledQueryCollector() {}

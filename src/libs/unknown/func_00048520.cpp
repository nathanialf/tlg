/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Nothing to destroy; the deleting destructor (0x48520, slot 1 of the
 * vtable 0x1699010) frees the collector's 0x40 bytes. */
hknpFlippedShapeCastQueryCollector::~hknpFlippedShapeCastQueryCollector() {}

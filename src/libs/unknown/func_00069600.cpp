/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Nothing to destroy; the deleting destructor (0x69600, slot 1 of the
 * vtable 0x169a6f0) frees the collector's 0x90 bytes. */
hknpClosestHitCollector::~hknpClosestHitCollector() {}

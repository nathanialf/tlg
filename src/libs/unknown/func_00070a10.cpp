/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 3 of the all-hits collector: no hints, the early-out
 * value back to the largest (the constant table's row 34), no hits. */
void hknpAllHitsCollector::reset()
{
    hints = 0;
    earlyOut = D_14b2060[34];
    hits.clear();
}

/* The destructor (0x70900): the collector emptied, then the hits' storage
 * given back when it is not the object's own; the deleting destructor
 * 0x70970 frees the 0x3f0 bytes after it. */
hknpAllHitsCollector::~hknpAllHitsCollector()
{
    reset();
}

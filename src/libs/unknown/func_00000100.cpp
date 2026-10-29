/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkMonitorStreamColorTable's destructor (slot 0 of its vtable): the color
 * pairs' names given back, then their array. The deleting destructor
 * (0x1a0, slot 1) is emitted beside it. */
hkMonitorStreamColorTable::~hkMonitorStreamColorTable() {}

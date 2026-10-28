/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 0 of its vtable (0x168f3b0): the debugger's reference released. */
hkcdPlanarEntity::~hkcdPlanarEntity()
{
    if (debugger) {
        debugger->removeReference();
    }
    debugger = 0;
}

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 0 of its vtable (0x168d100): the writer's reference, which the
 * constructor took, released. */
hkOstream::~hkOstream()
{
    if (writer) {
        writer->removeReference();
    }
    writer = 0;
}

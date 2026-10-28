/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Slot 0 of its vtable (0x168d3f0): the reference the constructor took
 * released. */
Object0000a280::~Object0000a280()
{
    if (object) {
        object->removeReference();
    }
    object = 0;
}

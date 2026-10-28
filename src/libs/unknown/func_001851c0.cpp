/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The stream's destructor (slot 0 of its vtable): the reader's reference
 * released. */
Object00185000::~Object00185000()
{
    if (reader) {
        reader->removeReference();
    }
    reader = 0;
}

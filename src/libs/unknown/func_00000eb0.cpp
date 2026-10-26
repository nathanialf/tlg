/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 0 of its vtable (0x168c3a0), the complete destructor: the writer
 * lives in the caller's buffer and is not released. */
BufferOstream::~BufferOstream()
{
    writer = 0;
}

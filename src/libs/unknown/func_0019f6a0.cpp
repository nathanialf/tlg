/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Nothing is written: the offset moves past the bytes and the end follows
 * it, and every byte counts as written. */
int OffsetStreamWriter::write(const void *buffer, int size)
{
    offset += size;
    end = offset > end ? offset : end;
    return size;
}

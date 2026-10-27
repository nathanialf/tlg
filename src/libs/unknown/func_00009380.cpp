/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the buffered writer's position: the buffered stream's
 * (none without one) plus the bytes still in the buffer, or -1 when the
 * stream has no position. */
int hkBufferedStreamWriter::FUN_00009380() const
{
    int streamPosition = stream ? stream->tell() : 0;
    if (streamPosition >= 0) {
        return streamPosition + bufferSize;
    }
    return -1;
}

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 11 of the buffered stream reader: the stream's
 * position less the bytes still buffered ahead of the read position, or -1
 * when the stream cannot tell. */
int BufferedStreamReader::FUN_00094720() const
{
    int streamPosition = seekableStream->tell();
    if (streamPosition >= 0) {
        return streamPosition - numBuffered + position;
    }
    return -1;
}

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 10 of the buffered stream reader's vtable (address
 * point 0x16a35d0): drops what is buffered and seeks the stream. */
hkResult BufferedStreamReader::FUN_00094700(int offset, int whence)
{
    position = 0;
    numBuffered = 0;
    return seekableStream->seek(offset, whence);
}

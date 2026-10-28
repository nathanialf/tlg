/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hkBufferedStreamWriter::FUN_000091f0() /* derived name */
{
    flushBuffer();
    if (stream) {
        stream->flush();
    }
}

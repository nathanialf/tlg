/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkBufferedStreamWriter::~hkBufferedStreamWriter()
{
    flushBuffer();
    if (stream) {
        stream->removeReference();
    }
    if (ownsBuffer) {
        FUN_0000bc00(*D_16dc070->temp58, buffer);
    }
}

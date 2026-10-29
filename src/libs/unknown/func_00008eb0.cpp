/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The writer over a stream it holds a reference to, with a buffer of its
 * own from the thread's heap, aligned to 64 bytes. */
hkBufferedStreamWriter::hkBufferedStreamWriter(hkStreamWriter *stream_, int bufferSize_)
    : stream(stream_), ownsBuffer(true)
{
    if (stream) {
        stream->addReference();
    }
    buffer = static_cast<char *>(FUN_0000bba0(*D_16dc070->temp58, bufferSize_, 64));
    bufferSize = 0;
    bufferCapacity = bufferSize_;
}

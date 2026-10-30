/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

BufferedStreamReader::~BufferedStreamReader()
{
    stream->removeReference();
    FUN_0000bc00(*D_16dc070->temp58, buffer);
}

/* A reader over the stream (0x94170): the stream held with a reference, its
 * seekable reader asked for, and a buffer of its own from the thread's heap,
 * aligned to 64 bytes. */
BufferedStreamReader::BufferedStreamReader(StreamReader *stream_, int bufferSize_) : stream(stream_)
{
    seekableStream = stream_->unknownVirtual9();
    buffer = static_cast<char *>(FUN_0000bba0(*D_16dc070->temp58, bufferSize_, 64));
    position = 0;
    numBuffered = 0;
    bufferSize = bufferSize_;
    stream->addReference();
}

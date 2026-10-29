/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The stream over the caller's buffer: its writer built in place in the
 * buffer's last bytes, over the bytes before them as a string, and taken
 * without a reference of its own (the old writer released unless it is the
 * same). */
BufferOstream::BufferOstream(char *buffer, int size) : hkOstream(0)
{
    hkBufferedStreamWriter *bufferWriter = new (buffer + size - sizeof(hkBufferedStreamWriter))
        hkBufferedStreamWriter(buffer, size - int(sizeof(hkBufferedStreamWriter)), true);
    if (writer && writer != bufferWriter) {
        writer->removeReference();
    }
    writer = bufferWriter;
}

/* src/libs/havok/Common/Base/System/Error/hkError.cpp:
 * the file its reports name (config/homes.base.txt, FUN_00000ee0). */
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

/* Slot 0 of its vtable (0x168c3a0), the complete destructor: the writer
 * lives in the caller's buffer and is not released. */
BufferOstream::~BufferOstream()
{
    writer = 0;
}

/* The file hkError.cpp's reports name (the string at 0x14b266c). */
#define HK_ERROR_CPP                                                                               \
    "Y:\\NightlyJobs\\20141121-01\\Source\\Common\\Base\\System\\Error\\hkError.cpp"

/* A message reported as an error from hkError.cpp itself (line 45; the
 * license check's two messages at 0x33847 and 0x33899): the stream over
 * the report's buffer built and destroyed here, inline. derived name. */
void FUN_00000ee0(const char *message)
{
    HK_ERROR(0x2636fe25, HK_ERROR_CPP, 45, message);
}

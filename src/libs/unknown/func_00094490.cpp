/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Up to size bytes read from a stream into a buffer, as long as it gives
 * any: the count read, none when the stream is not readable. derived
 * name. */
static int readAll(StreamReader *stream, char *buffer, int size) /* derived name */
{
    int numRead = 0;
    if (stream->isOk()) {
        while (size) {
            const int n = stream->read(buffer + numRead, size);
            if (n <= 0) {
                break;
            }
            numRead += n;
            size -= n;
        }
    }
    return numRead;
}

// NONMATCHING: 75 of 82, two placements only: the base materializes the
// refill loop's zero count in the loop's own preheader (after the size
// test, 0x94518), the compile in the block of the size test, and after the
// loop the base computes the two sums before it reloads this and stores the
// count buffered, the compile after (docs/NOTES.md, Round 61A).
int BufferedStreamReader::FUN_00094490(int numBytes)
{
    int numSkipped;
    int numAvailable;
    const int numLeft = numBuffered - position;
    if (numLeft >= numBytes) {
        numSkipped = 0;
        numAvailable = numLeft;
    } else {
        position = 0;
        numBuffered = 0;
        numBytes -= numLeft;
        const int numDirect = numBytes / 512;
        const int numSkippedDirect = stream->skip(numDirect);
        if (numSkippedDirect < numDirect) {
            return numLeft + numSkippedDirect;
        }
        numAvailable = readAll(stream, buffer, bufferSize);
        numSkipped = numLeft + numDirect;
        numBytes -= numDirect;
        numBuffered = numAvailable;
    }
    const int n = hkMath::min2(numBytes, numAvailable);
    position += n;
    return numSkipped + n;
}

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Up to size bytes read from a stream into a buffer, as long as it gives
 * any: the count read, none when the stream is not readable. derived
 * name. */
static int readAll(StreamReader *stream, void *buffer, int size) /* derived name */
{
    int numRead = 0;
    if (stream->isOk()) {
        while (size) {
            const int n = stream->read(hkAddByteOffset(buffer, numRead), size);
            if (n <= 0) {
                break;
            }
            numRead += n;
            size -= n;
        }
    }
    return numRead;
}

int BufferedStreamReader::read(void *dst, int numBytes)
{
    int numRead = 0;
    int numLeft = numBuffered - position;
    const char *src = buffer + position;
    while (numBytes > numLeft) {
        FUN_00017e70(hkAddByteOffset(dst, numRead), src, numLeft);
        position = 0;
        numBuffered = 0;
        numRead += numLeft;
        const int numFilled = readAll(stream, buffer, bufferSize);
        if (numFilled == 0) {
            return numRead;
        }
        numBuffered = numFilled;
        numBytes -= numLeft;
        numLeft = numFilled;
        src = buffer + position;
    }
    FUN_00017e70(hkAddByteOffset(dst, numRead), src, numBytes);
    position += numBytes;
    return numRead + numBytes;
}

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
        numBytes -= numDirect;
        numSkipped = numLeft + numDirect;
        numAvailable = readAll(stream, buffer, bufferSize);
        numBuffered = numAvailable;
    }
    const int n = hkMath::min2(numBytes, numAvailable);
    position += n;
    return numSkipped + n;
}

// NONMATCHING: 0x945a0, 71 of 98: the fill's guard. The base keeps the free
// space's subtraction in the guard's block after the readability test (`xor
// r13d, r13d; sub ebx, r15d; je`, the compare folded into the sub), where
// here InstCombine turns the rotated guard `size != 0` into `bufferSize !=
// numBuffered` and the subtraction sinks into the loop's preheader (`cmp ebx,
// r15d; je; sub ebx, r15d`). Lead: a guard that keeps reading the
// difference (docs/NOTES.md, Round 66A).
int BufferedStreamReader::peek(void *dst, int numBytes)
{
    if (bufferSize - 512 < numBytes) {
        return -1;
    }
    if (position + numBytes > numBuffered) {
        const int numLeft = numBuffered - position;
        const int newPosition = 512 - numLeft % 512;
        if (newPosition != position && numBuffered != position) {
            FUN_00091210(buffer + newPosition, buffer + position, numLeft);
        }
        position = newPosition;
        numBuffered = newPosition + numLeft;
        numBuffered += readAll(stream, buffer + numBuffered, bufferSize - numBuffered);
    }
    const int n = hkMath::min2(numBytes, numBuffered - position);
    FUN_000910e0(dst, buffer + position, n);
    return n;
}

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The bytes skipped by reading them into a buffer on the stack, 512 at a
 * time, until the count is reached or a read brings nothing: the count
 * skipped, taken from the bytes left before the last read. */
int StreamReader::skip(int numBytes)
{
    char buffer[512];
    int bytesLeft = numBytes;
    int bytesLeftBeforeRead;
    int bytesRead;
    do {
        bytesLeftBeforeRead = bytesLeft;
        if (bytesLeft == 0) {
            break;
        }
        bytesRead = read(buffer, bytesLeft > 512 ? 512 : bytesLeft);
        bytesLeft -= bytesRead;
    } while (bytesRead != 0);
    return numBytes - bytesLeftBeforeRead;
}

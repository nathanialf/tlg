/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The bytes skipped by reading them into a buffer on the stack, 512 at a
 * time, until the count is reached or a read brings nothing: the count
 * skipped. */
// NONMATCHING: 16 of 49 by position, one instruction short: the loop and
// its subtraction ahead of the test are the base's, but the exit after an
// empty read takes the count left after the subtraction where the base keeps
// the one before it (its copy into ecx, 0x8f0e1). With the test first
// (break, then subtract), which gives that exit value, LoopRotate folds the
// latch and then rotates the loop (a guard ahead of it), which the base's is
// not.
int StreamReader::skip(int numBytes)
{
    char buffer[512];
    int bytesLeft = numBytes;
    while (bytesLeft) {
        const int bytesRead = read(buffer, bytesLeft > 512 ? 512 : bytesLeft);
        bytesLeft -= bytesRead;
        if (bytesRead == 0) {
            break;
        }
    }
    return numBytes - bytesLeft;
}

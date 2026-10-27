/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Peek: the bytes read, then the handle moved back by as many from where
 * it stands (whence 1); nothing read, or a failed seek, leaves the reader
 * failed. */
int FiosStreamReader::FUN_00093340(void *buffer, int numBytes) /* derived name */
{
    const int numRead = int(sceFiosFHReadSync(0, handle, buffer, numBytes));
    if (numRead <= 0 || sceFiosFHSeek(handle, -numRead, 1) < 0) {
        ok = false;
    }
    return numRead;
}

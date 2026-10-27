/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Read: nothing from a handle that did not open or for no bytes; a read
 * that brings nothing leaves the reader failed. */
int FiosStreamReader::FUN_00093300(void *buffer, int numBytes) /* derived name */
{
    int numRead = 0;
    if (handle >= 0 && numBytes) {
        numRead = int(sceFiosFHReadSync(0, handle, buffer, numBytes));
        if (numRead <= 0) {
            ok = false;
        }
    }
    return numRead;
}

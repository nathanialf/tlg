/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 5 of the buffered stream reader's vtable (address
 * point 0x16a35d0): readable while bytes are still buffered, else as the
 * stream says. */
hkBool BufferedStreamReader::isOk() const
{
    return position != numBuffered || stream->isOk();
}

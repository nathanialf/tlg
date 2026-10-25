/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 9 of the buffered stream reader's vtable (address point
 * 0x16a35d0): the reader itself when its stream can seek and tell, else
 * null. */
BufferedStreamReader *BufferedStreamReader::FUN_000946f0() /* derived name */
{
    return seekableStream ? this : 0;
}

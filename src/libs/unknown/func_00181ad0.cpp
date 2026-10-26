/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 9 of the offset reader's vtable (address point
 * 0x16a6410): seeks the reader it wraps, an absolute position (whence 0)
 * moved by its start offset. */
int OffsetSeekableReader::FUN_00181ad0(int offset, int whence)
{
    if (whence == 0) {
        offset += start;
    }
    return reader->seek(offset, whence);
}

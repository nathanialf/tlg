/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 10 of the vtable at 0x16a6410 tells the inner reader's
 * position less the offset the reader starts at. */
int OffsetSeekableReader::FUN_00181af0() const
{
    return reader->tell() - start;
}

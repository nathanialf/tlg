/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

StreamReader *FiosFileSystem::FUN_0001a7b0(StreamReader *reader, int flags)
{
    if (reader == 0) {
        return 0;
    }
    if (flags & 1) {
        StreamReader *buffered = new BufferedStreamReader(reader, 0x4000);
        reader->removeReference();
        return buffered;
    }
    return reader;
}

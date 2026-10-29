/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkStreamWriter *FiosFileSystem::FUN_0001a850(hkStreamWriter *writer, int flags)
{
    if (writer == 0) {
        return 0;
    }
    if (flags & 1) {
        hkStreamWriter *buffered = new hkBufferedStreamWriter(writer, 0x1000);
        writer->removeReference();
        return buffered;
    }
    return writer;
}

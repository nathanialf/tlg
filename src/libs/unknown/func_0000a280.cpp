/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkOArchive::hkOArchive(hkStreamWriter *writer, bool byteSwap)
{
    if (writer) {
        writer->addReference();
    }
    this->writer = writer;
    this->byteSwap = byteSwap;
}

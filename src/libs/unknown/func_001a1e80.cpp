/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void FUN_001a1e80(hkStreamWriter *writer, int alignment)
{
    const int position = writer->tell();
    LocalArray<char> zeros(alignment);
    zeros.setSize(hkContainerHeapAllocator::get(), alignment, 0);
    const int misalignment = position & (alignment - 1);
    if (misalignment) {
        writer->write(zeros.data, alignment - misalignment);
    }
}

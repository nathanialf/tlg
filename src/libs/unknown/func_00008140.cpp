/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The stream over an array: its writer borrows the array and is taken
 * without a reference of its own (the old writer released unless it is the
 * same, as BufferOstream's constructor does). */
hkOstream::hkOstream(hkArray<char> &buffer) : writer(HK_NULL)
{
    hkArrayStreamWriter *arrayWriter =
        new hkArrayStreamWriter(&buffer, hkArrayStreamWriter::ARRAY_BORROW);
    if (writer && writer != arrayWriter) {
        writer->removeReference();
    }
    writer = arrayWriter;
}

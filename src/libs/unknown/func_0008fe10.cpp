/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkArrayStreamWriter's destructor (slot 0 of its vtable, 0x16a32f0): an
 * array the writer took goes back to the thread's heap at its 16 bytes. */
hkArrayStreamWriter::~hkArrayStreamWriter()
{
    if (ownership == ARRAY_TAKE && array) {
        D_16dc070->temp58->blockFree(array, sizeof(hkArray<char>));
    }
}

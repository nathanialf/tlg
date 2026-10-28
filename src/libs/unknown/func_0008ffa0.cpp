/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkArrayStreamWriter::FUN_0008ffa0()
{
    array->clear();
    offset = 0;
    array->reserve(*allocator, array->getSize() + 1);
    array->data[array->getSize()] = 0;
}

/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void BitFieldMap00199770::FUN_00199880()
{
    for (U16PointerMap::Iterator it = fields.getIterator(); fields.isValid(it);
         it = fields.getNext(it)) {
        Block *block = reinterpret_cast<Block *>(fields.getValue(it));
        D_16dc070->temp58->blockFree(block, block->numBytes);
    }
    fields.clear();
}

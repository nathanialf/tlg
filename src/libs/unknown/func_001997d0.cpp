/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void BitFieldMap00199770::FUN_001997d0(int bitIndex)
{
    for (U16PointerMap::Iterator it = fields.getIterator(); fields.isValid(it);
         it = fields.getNext(it)) {
        hkBitField &bits = reinterpret_cast<Block *>(fields.getValue(it))->bits;
        if (u32(bitIndex) < u32(bits.storage.numBits)) {
            bits.clear(bitIndex);
        }
    }
}

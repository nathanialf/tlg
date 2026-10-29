/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void FUN_00066080(const Object00065f20 *self, hkBitField &bitsOut) /* derived name */
{
    bitsOut.FUN_00047b30(0, self->records[0].bits.storage.numBits, 0);
    for (int i = 0; i < self->numRecords; i++) {
        bitsOut.orWith(self->records[i].bits);
    }
}

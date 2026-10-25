/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* derived names: slot 11 of the vtable at 0x168ca00, an allocator over the
 * system heap: slot 2 (0x4ad0) adds the size atomically to the bytes in use
 * at +0xc, raises the peak at +0x10 to it and allocates with the alignment
 * at +8; slot 3 subtracts and frees; slot 9 reports both counts widened to
 * 64 bits. This one resets the peak to the current use. Also called directly
 * from six places in the game region. */
class Allocator00004b10 /* derived name */
{
  public:
    virtual ~Allocator00004b10();

    void FUN_00004b10(); /* vtable slot 11; derived name */

    int alignment;  /* derived name */
    u32 bytesInUse; /* derived name */
    u32 peakInUse;  /* derived name */
};

void Allocator00004b10::FUN_00004b10() /* derived name */
{
    peakInUse = bytesInUse;
}

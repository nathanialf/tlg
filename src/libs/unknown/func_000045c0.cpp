/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the class chain walked from the class to its root, every
 * class written into one CRC, or the class alone when the flags' bit 0 is
 * set; the CRC is returned complemented. */
// NONMATCHING: the base unswitches the loop on the flag (0x4602: the class
// written once when it is set, the walk when it is not), LoopUnswitch's
// non-trivial unswitch, which 3.3 builds with OptimizeForSize below -O3
// (PassManagerBuilder.cpp:189) and so refuses at -O2; D21's question
// (docs/NOTES.md, Round 52).
u32 hkClass::FUN_000045c0(int signatureFlags) const
{
    Crc32StreamWriter crc;
    const hkClass *c = this;
    while (c) {
        c->FUN_00004660(&crc);
        c = (signatureFlags & 1) ? 0 : c->parent;
    }
    return ~crc.crc;
}

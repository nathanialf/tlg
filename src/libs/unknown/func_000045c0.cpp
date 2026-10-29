/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the class chain walked from the class to its root, every
 * class written into one CRC, or the class alone when the flags' bit 0 is
 * set; the CRC is returned complemented, and no class gives 0. */
u32 hkClass::FUN_000045c0(int signatureFlags) const
{
    Crc32StreamWriter crc;
    const hkClass *c = this;
    if (!c) {
        return 0;
    }
    if (signatureFlags & 1) {
        c->FUN_00004660(&crc);
    } else {
        do {
            c->FUN_00004660(&crc);
            c = c->parent;
        } while (c);
    }
    return ~crc.crc;
}

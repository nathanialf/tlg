/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 80 of Object00c29c00's vtable (its pointer at
 * 0x16b8718): rebuilds the 16-bit mask at +0x78 of its argument, a bit for
 * each of the first 16 entries of the pointer array at +0x60 (its count at
 * +0x68) that is set and is not the object at +0x20 of the record the
 * pointer at +0x38 of the object at 0x5938c40 holds. The mask is written
 * back as each bit is set. Its first argument is unused; the types are not
 * traced. */
struct Entry00c68f30; /* derived name */

struct Record05938c40_38 { /* derived name */
    u8 unknown0[0x20];
    Entry00c68f30 *unknown20; /* +0x20 */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x38];
    Record05938c40_38 *unknown38; /* +0x38 */
};

extern Object05938c40 *D_5938c40;

struct Argument00c68f30 { /* derived name */
    u8 unknown0[0x60];
    Entry00c68f30 **unknown60; /* +0x60 */
    u32 unknown68;             /* +0x68: the count of +0x60 */
    u8 unknown6c[0xc];
    u32 unknown78; /* +0x78: the mask */
};

class Object00c29c00; /* derived name */

// NONMATCHING: the count compare: the base compares the 32-bit count with the
// truncated counter (`cmp eax, ecx; jbe`), this build widens the count and
// compares 64 bits (IndVarSimplify's widenLoopCompare, absent in 3.6.2).
void FUN_00c68f30(Object00c29c00 *, Argument00c68f30 *argument) /* derived name */
{
    argument->unknown78 = 0;
    for (u32 i = 0; i < 16; i++) {
        if (i < argument->unknown68 && argument->unknown60[i] &&
            argument->unknown60[i] != D_5938c40->unknown38->unknown20)
            argument->unknown78 |= 1 << i;
    }
}

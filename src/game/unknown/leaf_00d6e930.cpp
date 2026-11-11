/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16baa98 (+0x50 from the vtable stored at
 * 0x16baa48): unless bit 3 of the argument's flags at +0x48 or a bit of 0x6 of
 * its byte at +0x70 is set, passes the record at +0x38 of the object the
 * pointer at 0x5938c40 holds, 0, the address of the argument's +0xc and 9 when
 * bit 2 of the flags is set, else 1, to FUN_00d44120. FUN_00d6e970 (slot
 * +0x70) is its sibling. The object itself is not read; the classes and the
 * callee's return type are not traced. */
struct Member05938c40_38; /* derived name */

struct Object05938c40 { /* derived name */
    u8 unknown0[0x38];
    Member05938c40_38 *unknown38;
};

extern Object05938c40 *D_5938c40;

struct Argument00d6e930 { /* derived name */
    u8 unknown0[0xc];
    u8 unknownc[0x3c];
    unsigned unknown48;
    u8 unknown4c[0x24];
    u8 unknown70;
};

void FUN_00d44120(Member05938c40_38 *record, int value, void *entry, int mode); /* derived name */

struct Object00d6e930; /* derived name */

// NONMATCHING: the base calls FUN_00d44120 and returns (no sibling call) where the build tail-calls it; nothing in the bytes shows what kept the call from being marked tail (an escaping local removed after TailCallElim would): open
void FUN_00d6e930(Object00d6e930 *, Argument00d6e930 *argument) /* derived name */
{
    unsigned flags = argument->unknown48;
    if ((flags & 8) || (argument->unknown70 & 6)) {
        return;
    }
    FUN_00d44120(D_5938c40->unknown38, 0, argument->unknownc, (flags & 4) ? 9 : 1);
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a virtual method (its address at 0x16b2318 in
 * .data.rel.ro): when the byte at +0xa0 is set, runs FUN_00b72f70 on the
 * member at +0x98 unless the int at +0x1bc of the object the pointer at
 * 0x5938c40 holds is set, then FUN_00b738b0 on it, a tail call. Class and
 * method unknown; the member's type is not traced. */
struct Object05938c40 { /* derived name */
    u8 unknown0[0x1bc];
    int unknown1bc; /* +0x1bc */
};

extern Object05938c40 *D_5938c40;

struct Member00a646f0 { /* derived name */
    u8 unknown0[8];
};

struct Object00a646f0 { /* derived name */
    u8 unknown0[0x98];
    Member00a646f0 unknown98; /* +0x98 */
    bool unknowna0;           /* +0xa0 */
};

void FUN_00b72f70(Member00a646f0 *member); /* derived name */
void FUN_00b738b0(Member00a646f0 *member); /* derived name */

void FUN_00a646f0(Object00a646f0 *self) /* derived name */
{
    if (self->unknowna0) {
        if (!D_5938c40->unknown1bc)
            FUN_00b72f70(&self->unknown98);
        FUN_00b738b0(&self->unknown98);
    }
}

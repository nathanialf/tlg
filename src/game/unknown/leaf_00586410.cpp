/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a handler FUN_00525530 stores among the function pointers
 * from +0x4118 of the object it builds: runs FUN_00c0a000 on the object and
 * keeps the three flag words at +0x10, +0x14 and +0x18 of the record its
 * pointer at +0x118 holds, read before the call and or'ed back after it (the
 * record read again each time); returns 0. The record and the handler's
 * meaning are not traced. */
struct Record00586410 { /* derived name */
    u8 unknown0[0x10];
    u32 flags10; /* +0x10 */
    u32 flags14; /* +0x14 */
    u32 flags18; /* +0x18 */
};

struct Object00586410 { /* derived name */
    u8 unknown0[0x118];
    Record00586410 *unknown118; /* +0x118 */
};

void FUN_00c0a000(Object00586410 *self); /* derived name */

int FUN_00586410(Object00586410 *self) /* derived name */
{
    const u32 flags10 = self->unknown118->flags10;
    const u32 flags14 = self->unknown118->flags14;
    const u32 flags18 = self->unknown118->flags18;
    FUN_00c0a000(self);
    self->unknown118->flags10 |= flags10;
    self->unknown118->flags14 |= flags14;
    self->unknown118->flags18 |= flags18;
    return 0;
}

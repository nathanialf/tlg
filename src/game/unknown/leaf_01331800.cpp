/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the complete destructor of a handle, registered with
 * __cxa_atexit for the globals FUN_001b0680 and FUN_001b1ef0 initialize (and
 * for 0x582b200, leaf_00ac0d90.cpp's): when its index is nonzero, an atomic
 * decrement of the int at +0x10 of the 32-byte entry of the table at
 * 0x17ac870 the index selects, FUN_00d66e30 with the index (reloaded) when
 * that was the last reference, then the index cleared. Written as a free
 * function on the record, as the region's other complete destructors of
 * globals are. */
struct Entry017ac870 { /* derived name */
    u8 unknown0[0x10];
    int unknown10; /* +0x10: the references */
    u8 unknown14[0xc];
};

extern Entry017ac870 D_17ac870[];

struct Object01331800 /* derived name */
{
    unsigned index; /* derived name */
};

void FUN_00d66e30(unsigned index); /* derived name */

void FUN_01331800(Object01331800 *self) /* derived name */
{
    if (self->index) {
        if (__sync_fetch_and_sub(&D_17ac870[self->index].unknown10, 1) == 1)
            FUN_00d66e30(self->index);
        self->index = 0;
    }
}

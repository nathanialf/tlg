/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: passes the object at +0x98 of the object the pointer at
 * 0x5938c40 holds, the pointers at +0x58 and +0x60 of the object and 1.0 to
 * FUN_00c66b10 and returns 1; slot 5 of the vtable at 0x16af1f8 (its pointer
 * at 0x16af230), stored by FUN_008726f0 and FUN_013723f0. The types beyond the
 * widths and the callee's return type are not traced. */
struct Member05938c40_98; /* derived name */

struct Object05938c40 { /* derived name */
    u8 unknown0[0x98];
    Member05938c40_98 *unknown98;
};

extern Object05938c40 *D_5938c40;

struct Object008728d0 { /* derived name */
    u8 unknown0[0x58];
    void *unknown58;
    void *unknown60;
};

void FUN_00c66b10(Member05938c40_98 *member, void *first, void *second,
                  float value); /* derived name */

int FUN_008728d0(Object008728d0 *self) /* derived name */
{
    FUN_00c66b10(D_5938c40->unknown98, self->unknown58, self->unknown60, 1.0f);
    return 1;
}

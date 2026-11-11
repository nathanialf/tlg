/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: for the arguments 1 and 0, passes the pointer at +0x1b8 of
 * the object the pointer at 0x5827ee0 holds to FUN_01367fa0 when it is not
 * null; returns 1. Slot 6 of the vtable at 0x16b2298 (its pointer at
 * 0x16b22d8), stored by FUN_00a5d530 and FUN_00a5e250. The object itself is
 * not read; the callee's return type is not traced. */
struct Object00a63b50;     /* derived name */
struct Member05827ee0_1b8; /* derived name */

struct Object05827ee0 { /* derived name */
    u8 unknown0[0x1b8];
    Member05827ee0_1b8 *unknown1b8;
};

extern Object05827ee0 *D_5827ee0;

void FUN_01367fa0(Member05827ee0_1b8 *member); /* derived name */

int FUN_00a63b50(Object00a63b50 *, int first, int second) /* derived name */
{
    if (first == 1 && second == 0) {
        Member05827ee0_1b8 *member = D_5827ee0->unknown1b8;
        if (member)
            FUN_01367fa0(member);
    }
    return 1;
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a function FUN_00ad3090 stores the address of (lea at
 * 0xad3d64): calls FUN_00ad4580 with the addresses of the fields at +0xc,
 * +0x10 and +0x14, as a tail call. The fields' types and the return type are
 * not traced. Class and method unknown. */
struct Object00ad06b0 { /* derived name */
    u8 unknown0[0xc];
    int unknownc;
    int unknown10;
    int unknown14;
};

void FUN_00ad4580(int *first, int *second, int *third); /* derived name */

void FUN_00ad06b0(Object00ad06b0 *self) /* derived name */
{
    FUN_00ad4580(&self->unknownc, &self->unknown10, &self->unknown14);
}

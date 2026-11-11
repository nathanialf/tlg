/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 69 of the vtable at 0x16bb0c0 (its pointer at
 * 0x16bb2f8): clears the int the record at +0x16f0 of the object at +0x7dc8
 * points to, and the int at +0x7de4. Class and method unknown. */
struct Record00dad680 { /* derived name */
    u8 unknown0[0x16f0];
    int *unknown16f0;
};

struct Object00dad680 { /* derived name */
    u8 unknown0[0x7dc8];
    Record00dad680 *unknown7dc8;
    u8 unknown7dd0[0x14];
    int unknown7de4;
};

void FUN_00dad680(Object00dad680 *self) /* derived name */
{
    *self->unknown7dc8->unknown16f0 = 0;
    self->unknown7de4 = 0;
}

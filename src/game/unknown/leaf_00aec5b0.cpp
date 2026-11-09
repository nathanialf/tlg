/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00aec5d0 with the object as a tail call when the
 * int at +0x30 of the record reached through the pointers at +0x1b0 and +0x408
 * is set; called by FUN_0059c8e0. Class and method unknown. */
struct Record00aec5b0B { /* derived name */
    u8 unknown0[0x30];
    int unknown30;
};

struct Record00aec5b0A { /* derived name */
    u8 unknown0[0x408];
    Record00aec5b0B *unknown408;
};

struct Object00aec5b0 { /* derived name */
    u8 unknown0[0x1b0];
    Record00aec5b0A *unknown1b0;
};

void FUN_00aec5d0(Object00aec5b0 *self); /* derived name */

void FUN_00aec5b0(Object00aec5b0 *self) /* derived name */
{
    if (self->unknown1b0->unknown408->unknown30) {
        FUN_00aec5d0(self);
    }
}

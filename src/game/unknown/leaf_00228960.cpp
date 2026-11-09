/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback (its address taken by FUN_00225e40): calls
 * FUN_00aa55a0 with the pointer at +0x138 of the record the pointer at +0x10
 * holds, that record and the float at +0x18, as a tail call. The types are not
 * traced. */
struct Target00228960; /* derived name */

struct Record00228960 { /* derived name */
    u8 unknown0[0x138];
    Target00228960 *unknown138;
};

struct Object00228960 { /* derived name */
    u8 unknown0[0x10];
    Record00228960 *unknown10;
    float unknown18;
};

void FUN_00aa55a0(Target00228960 *target, Record00228960 *record, float value); /* derived name */

void FUN_00228960(Object00228960 *self) /* derived name */
{
    FUN_00aa55a0(self->unknown10->unknown138, self->unknown10, self->unknown18);
}

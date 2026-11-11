/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16c0c70 (+0x20 from the vtable stored at
 * 0x16c0c50): passes the object to FUN_013ed810, then zeroes its 32-bit
 * fields at +0xb0, +0xd4 and +0xb4, in that order. The class, the fields'
 * types and the callee's return type are not traced. */
struct Object013eeec0 { /* derived name */
    u8 unknown0[0xb0];
    int unknownb0;
    int unknownb4;
    u8 unknownb8[0x1c];
    int unknownd4;
};

void FUN_013ed810(Object013eeec0 *self); /* derived name */

// NONMATCHING: store merging: the base keeps the three dword stores (+0xb0, +0xd4, +0xb4), the build merges +0xb0 and +0xb4 across the +0xd4 store into one qword store (an int or a float at +0xb4 alike); a game-line form of D27's one run per visit is the lead
void FUN_013eeec0(Object013eeec0 *self) /* derived name */
{
    FUN_013ed810(self);
    self->unknownb0 = 0;
    self->unknownd4 = 0;
    self->unknownb4 = 0;
}

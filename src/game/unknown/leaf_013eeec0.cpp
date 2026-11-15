/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16c0c70 (+0x20 from the vtable stored at
 * 0x16c0c50): passes the object to FUN_013ed810, then zeroes its 32-bit
 * fields at +0xb0, +0xd4 and +0xb4, in that order. The class, the fields'
 * types and the callee's return type are not traced. */
struct Object013eeec0 { /* derived name */
    u8 unknown0[0xb0];
    float unknownb0; /* a float: the base keeps its zero apart from the int's at +0xb4 */
    int unknownb4;
    u8 unknownb8[0x1c];
    int unknownd4;
};

void FUN_013ed810(Object013eeec0 *self); /* derived name */

void FUN_013eeec0(Object013eeec0 *self) /* derived name */
{
    FUN_013ed810(self);
    self->unknownb0 = 0.0f;
    self->unknownd4 = 0;
    self->unknownb4 = 0;
}

/* src/unknown/: functions matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_00015ae0 on the object at +0x18, then clears a
 * 16-bit and an 8-bit field at +0x360 and +0x362. Unknown owner. */
struct Unknown15ae0;
void FUN_00015ae0(Unknown15ae0 *); /* derived name */

struct Owner17a60 {
    u8 unknown0[0x18];
    Unknown15ae0 *target;
    u8 unknown20[0x360 - 0x20];
    u16 flags;
    u8 state;
};

void FUN_00017a60(Owner17a60 *self) /* derived name */
{
    FUN_00015ae0(self->target);
    self->flags = 0;
    self->state = 0;
}

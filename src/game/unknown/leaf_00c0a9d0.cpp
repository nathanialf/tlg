/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_00be6da0 takes (lea at
 * 0xbe7515): passes the device at +0xf0, when there is one, and the field at
 * +0x38 of its argument to FUN_00c0a830; returns 0. The argument's type is not
 * traced. Handler unknown. */
struct Record00c0a9d0 { /* derived name */
    u8 unknown0[0x38];
    u8 unknown38;
};

void FUN_00c0a830(Device583950 *device, void *field); /* derived name */

int FUN_00c0a9d0(Owner583950 *self, Record00c0a9d0 *arg) /* derived name */
{
    if (self->device) {
        FUN_00c0a830(self->device, &arg->unknown38);
    }
    return 0;
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_00525530 (lea at 0x5258ec),
 * FUN_0058c760 and FUN_00be6da0 take: asks the device at +0xf0 for a 12-byte
 * slot for its argument (method 0 with 12, as FUN_00599dc0) and clears its
 * first word and two ints when it gets one; returns 0. The first word is typed
 * float because its store is not merged with the two ints' (the base stores 4
 * bytes at +0 and 8 at +4). Handler unknown. */
struct Slot00c02f80 { /* derived name */
    float unknown0;
    int unknown4;
    int unknown8;
};

int FUN_00c02f80(Owner583950 *self, void *arg) /* derived name */
{
    Slot00c02f80 *slot =
        static_cast<Slot00c02f80 *>(self->device->vtable->method0(self->device, arg, 12));
    if (slot) {
        slot->unknown0 = 0.0f;
        slot->unknown4 = 0;
        slot->unknown8 = 0;
    }
    return 0;
}

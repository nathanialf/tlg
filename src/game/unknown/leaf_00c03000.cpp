/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>
#include "tlg_device_thunk.h"

/* derived names: a record of 0x1d6 bytes (16-bit fields: the base clears
 * 0x1d6 bytes and asks for 0x1d8) with no constructor of its own
 * (value-initialised: all zero). Its fields are not traced. */
struct Record00c03000 { /* derived name */
    u16 unknown0[0x1d6 / 2];
};

/* derived names: a handler whose address the handler tables take (lea at
 * 0x58cabf, 0xbe756e and 0xc04b0f; as FUN_00c03260): asks the device at
 * +0xf0 for a slot of the record's size rounded up to 8 (0x1d8) for its argument (method 0) and clears a
 * Record00c03000 in it (placement new, the slot tested first); returns 0.
 * Handler unknown. */
int FUN_00c03000(Owner583950 *self, void *arg) /* derived name */
{
    void *slot =
        self->device->vtable->method0(self->device, arg, (sizeof(Record00c03000) + 7) & ~7);
    if (slot)
        new (slot) Record00c03000();
    return 0;
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_device_thunk.h"
#include "tlg_game_array01343a80.h"

/* derived names: the record FUN_00596ba0 builds in its slot: a locked
 * array, an eight-byte field cleared and five locked arrays (their element
 * types not traced; each lock made free after its array's owner index:
 * `mov dword [rbx+0x14], 0`), 0x98 bytes. */
struct Record596ba0 { /* derived name */

    Record596ba0() : unknown18(0) {}

    Array01343a80<void *> unknown0;
    void *unknown18;                 /* +0x18 */
    Array01343a80<void *> unknown20; /* +0x20 */
    Array01343a80<void *> unknown38; /* +0x38 */
    Array01343a80<void *> unknown50; /* +0x50 */
    Array01343a80<void *> unknown68; /* +0x68 */
    Array01343a80<void *> unknown80; /* +0x80 */
};

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x52599e): asks the device at +0xf0 for a slot for its argument (method
 * 0, the record's size rounded up to 16 bytes) and builds a Record596ba0 in
 * it (placement new, the slot tested first); returns 0. Handler unknown. */
int FUN_00596ba0(DeviceOwner583950 *self, void *arg) /* derived name */
{
    void *slot =
        self->device->vtable->method0(self->device, arg, (sizeof(Record596ba0) + 15) & ~15);
    if (slot)
        new (slot) Record596ba0();
    return 0;
}

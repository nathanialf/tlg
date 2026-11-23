/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_device_thunk.h"
#include "tlg_game_array01343a80.h"

/* derived names: three eight-byte fields and an int, cleared when made (28
 * bytes of fields in 32: the record of FUN_005a00c0 clears 0x120 to 0x13c
 * and 0x140 to 0x15c). */
struct Block5a00c0 { /* derived name */

    Block5a00c0() : unknown0(0), unknown8(0), unknown10(0), unknown18(0) {}

    void *unknown0;
    void *unknown8;  /* +0x8 */
    void *unknown10; /* +0x10 */
    int unknown18;   /* +0x18 */
};

/* derived names: the record FUN_005a00c0 builds in its slot: twelve locked
 * arrays (their element types not traced), two Block5a00c0, an int and two
 * eight-byte fields cleared, 0x178 bytes. */
struct Record5a00c0 { /* derived name */

    Record5a00c0() : unknown160(0), unknown168(0), unknown170(0) {}

    Array01343a80<void *> unknown0[12]; /* +0x0 */
    Block5a00c0 unknown120;             /* +0x120 */
    Block5a00c0 unknown140;             /* +0x140 */
    int unknown160;                     /* +0x160 */
    void *unknown168;                   /* +0x168 */
    void *unknown170;                   /* +0x170 */
};

/* derived names: a handler whose address FUN_00525530 takes: asks the device
 * at +0xf0 for a slot for its argument (method 0, the record's size) and
 * builds a Record5a00c0 in it (placement new, the slot tested first);
 * returns 0. Handler unknown. */
int FUN_005a00c0(DeviceOwner583950 *self, void *arg) /* derived name */
{
    void *slot = self->device->vtable->method0(self->device, arg, sizeof(Record5a00c0));
    if (slot)
        new (slot) Record5a00c0();
    return 0;
}

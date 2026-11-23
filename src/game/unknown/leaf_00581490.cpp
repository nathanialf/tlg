/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_device_thunk.h"
#include "tlg_game_array01343a80.h"

/* derived names: the record FUN_00581490 builds in its slot: three eight-byte
 * fields cleared, a lock word, eleven locked arrays (their element types not
 * traced), an int and three eight-byte fields cleared, 0x148 bytes. */
struct Record581490 { /* derived name */

    Record581490()
        : unknown0(0), unknown8(0), unknown10(0), unknown128(0), unknown130(0), unknown138(0),
          unknown140(0)
    {
        __sync_lock_release(&lock);
    }

    void *unknown0;
    void *unknown8;  /* +0x8 */
    void *unknown10; /* +0x10 */
    /* +0x18: a lock word, made free last by a release (an atomic store, which
     * the clears of +0x130 to +0x148 do not pass: `mov qword [rbx+0x18], 0`
     * after them) */
    s64 lock;
    Array01343a80<void *> unknown20[11]; /* +0x20 */
    int unknown128;                      /* +0x128 */
    void *unknown130;                    /* +0x130 */
    void *unknown138;                    /* +0x138 */
    void *unknown140;                    /* +0x140 */
};

/* derived names: a handler whose address FUN_00525530 takes: asks the device
 * at +0xf0 for a slot for its node (method 0, the record's size) and builds
 * a Record581490 in it (placement new, the slot tested first), then hands
 * the node's child at +0x28 to the handler of its kind; returns 0. Handler
 * unknown. */
int FUN_00581490(DeviceOwner583950 *self, Node583950 *node) /* derived name */
{
    void *slot = self->device->vtable->method0(self->device, node, sizeof(Record581490));
    if (slot)
        new (slot) Record581490();
    self->dispatch(node->child);
    return 0;
}

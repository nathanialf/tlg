/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_device_thunk.h"
#include "tlg_game_block.h"

/* derived names: the base whose destructor is the one at 0x13a1e00 (its row
 * named for it, D15; leaf_013a1df0.cpp); its constructor is inline and clears
 * the 0x20 bytes after the vtable pointer. */
class Object013a1e00 /* derived name */
{
  public:
    Object013a1e00() : unknown8() {}

    virtual ~Object013a1e00();

  private:
    u8 unknown8[0x20];
};

struct Member00c03260; /* derived name */

void FUN_00bebb40(Member00c03260 *self); /* derived name: its teardown before the release */

/* derived names: the class whose vtable is at 0x16d05d8
 * (config/vtables.derived.base.txt); its destructor 0x13a2180 (the key
 * function, so this file emits the vtable) tears down and releases the
 * object the pointer at +0x28 holds (tlg_game_block.h), then runs the
 * base's; the deleting one 0x13a21f0 is the compiler's. 0x30 bytes. */
class Object00c03260 : public Object013a1e00 /* derived name */
{
  public:
    Object00c03260() : unknown28(0) {}

    virtual ~Object00c03260();

  private:
    Member00c03260 *unknown28; /* +0x28 */
};

/* derived names: a handler whose address the handler tables take (as
 * FUN_00c02f80): asks the device at +0xf0 for a 0x30-byte slot for its
 * argument (method 0) and constructs an Object00c03260 in it (placement new,
 * the slot tested first); returns 0. Handler unknown. */
int FUN_00c03260(Owner583950 *self, void *arg) /* derived name */
{
    void *slot = self->device->vtable->method0(self->device, arg, sizeof(Object00c03260));
    if (slot)
        new (slot) Object00c03260();
    return 0;
}

Object00c03260::~Object00c03260()
{
    if (Member00c03260 *member = unknown28) {
        FUN_00bebb40(member);
        releaseBlock(member);
    }
}

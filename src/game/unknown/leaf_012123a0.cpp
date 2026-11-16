/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_types.h"

/* derived names: an object told of the caller through slot 5 of its vtable;
 * the other slots are not traced */
class Listener012123a0 /* derived name */
{
  public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void notify(void *source); /* derived name */
};

/* derived names: an entry of 24 bytes of the owner's array at +0x290, its
 * listener at +0x8 */
struct Entry012123a0 { /* derived name */
    u8 unknown0[0x8];
    Listener012123a0 *listener; /* +0x8 */
    u8 unknown10[0x8];
};

struct Owner012123a0 { /* derived name */
    u8 unknown0[0x290];
    Array05943280<Entry012123a0> entries; /* +0x290 */
};

struct Object012123a0 { /* derived name */
    u8 unknown0[0x8];
    Owner012123a0 *owner; /* +0x8 */
    u8 unknown10[0x60];
    int unknown70; /* +0x70: cleared after the listeners are told */
};

void FUN_01475f20(Object012123a0 *self); /* derived name; not traced */

/* derived name: FUN_01475f20, then every listener of the owner told of the
 * object (the owner's count read again at each one), then +0x70 cleared */
void FUN_012123a0(Object012123a0 *self) /* derived name */
{
    FUN_01475f20(self);
    for (unsigned i = 0; i < self->owner->entries.size(); ++i)
        self->owner->entries.at(i).listener->notify(self);
    self->unknown70 = 0;
}

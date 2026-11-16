/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_types.h"

/* derived names: an object told of the caller through slot 2 of its vtable;
 * the other slots are not traced */
class Listener01211da0 /* derived name */
{
  public:
    virtual void slot0();
    virtual void slot1();
    virtual void notify(void *source); /* derived name */
};

/* derived names: an entry of 24 bytes of the owner's array at +0x290, its
 * listener at +0x8 */
struct Entry01211da0 { /* derived name */
    u8 unknown0[0x8];
    Listener01211da0 *listener; /* +0x8 */
    u8 unknown10[0x8];
};

struct Owner01211da0 { /* derived name */
    u8 unknown0[0x290];
    Array05943280<Entry01211da0> entries; /* +0x290 */
};

struct Object01211da0 { /* derived name */
    u8 unknown0[0x8];
    Owner01211da0 *owner; /* +0x8 */
    u8 unknown10[0x60];
    int unknown70; /* +0x70: cleared after the listeners are told */
};

void FUN_01475f20(Object01211da0 *self); /* derived name; not traced */

/* derived name: FUN_01475f20, then every listener of the owner told of the
 * object (the owner's count read again at each one), then +0x70 cleared */
void FUN_01211da0(Object01211da0 *self) /* derived name */
{
    FUN_01475f20(self);
    for (unsigned i = 0; i < self->owner->entries.size(); ++i)
        self->owner->entries.at(i).listener->notify(self);
    self->unknown70 = 0;
}

/* src/include/tlg_game_object016cbca0.h: the class whose vtable is at
 * 0x16cbca0, a base of game classes (game region; docs/TARGETS.md). Every name
 * here is derived. */
#ifndef TLG_GAME_OBJECT016CBCA0_H
#define TLG_GAME_OBJECT016CBCA0_H

#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cbca0
 * (config/vtables.derived.base.txt, stored by FUN_007adf30 FUN_0136d4c0 FUN_0136d610 and 4 more), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_0136da00 tears them down
 * (the Names at +0x84, +0x80); the rest are not traced. */
class Object016cbca0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cbca0();

  private:
    u8 unknown24[0x5c];
    Name name80; /* +0x80: released by the destructor (`mov eax, [rbx+0x80]; shl 5`) */
    Name name84; /* +0x84: released by the destructor (`mov eax, [rbx+0x84]; shl 5`) */
};

/* derived name: the complete destructor (slot 0 of 0x16cbca0, FUN_0136da00): the
 * body is empty; the two Names are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_0136db00,
 * slot 1, is the deleting one. Defined here, inline: the destructors of the
 * derived classes hold this body, and with no key function the class's
 * vtable and its two destructors are emitted by a unit that stores the
 * vtable (leaf_0136d760.cpp, the row's unit). */
inline Object016cbca0::~Object016cbca0() {}

#endif

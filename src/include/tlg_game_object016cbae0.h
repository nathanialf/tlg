/* src/include/tlg_game_object016cbae0.h: the class whose vtable is at
 * 0x16cbae0, a base of game classes (game region; docs/TARGETS.md). Every name
 * here is derived. */
#ifndef TLG_GAME_OBJECT016CBAE0_H
#define TLG_GAME_OBJECT016CBAE0_H

#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cbae0
 * (config/vtables.derived.base.txt, stored by FUN_007ad260 FUN_0136e240 FUN_0136e390 and 4 more), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_0136e780 tears them down
 * (the Names at +0x94, +0x90); the rest are not traced. */
class Object016cbae0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cbae0();

  private:
    u8 unknown24[0x6c];
    Name name90; /* +0x90: released by the destructor (`mov eax, [rbx+0x90]; shl 5`) */
    Name name94; /* +0x94: released by the destructor (`mov eax, [rbx+0x94]; shl 5`) */
};

/* derived name: the complete destructor (slot 0 of 0x16cbae0, FUN_0136e780): the
 * body is empty; the two Names are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_0136e880,
 * slot 1, is the deleting one. Defined here, inline: the destructors of the
 * derived classes hold this body, and with no key function the class's
 * vtable and its two destructors are emitted by a unit that stores the
 * vtable (leaf_0136e4e0.cpp, the row's unit). */
inline Object016cbae0::~Object016cbae0() {}

#endif

/* src/include/tlg_game_object013d6840.h: the class whose vtable is at
 * 0x16d3b70 (game region; docs/TARGETS.md), its destructor in
 * leaf_013d6840.cpp, and a member at +0x30 of the class whose vtable is at
 * 0x16d3b98 (leaf_013d66e0.cpp). Every name here is derived. */
#ifndef TLG_GAME_OBJECT013D6840_H
#define TLG_GAME_OBJECT013D6840_H

#include "tlg_types.h"

/* derived names: the class of the vtable at 0x16d3b70
 * (config/vtables.derived.base.txt): its destructor (FUN_013d6840) stores
 * the vtable and releases the block the pointer at +0x18 holds
 * (tlg_game_block.h). The destructor is the class's key function, so
 * leaf_013d6840.cpp emits the vtable. The other members are not traced. */
class Object013d6840 /* derived name */
{
  public:
    virtual ~Object013d6840();

  private:
    u8 unknown8[0x10];
    void *unknown18; /* +0x18: owned block */
};

#endif

/* src/include/tlg_game_object013d6840.h: the class whose vtable is at
 * 0x16d3b70 (game region; docs/TARGETS.md), its destructor in
 * leaf_013d6840.cpp, and a member at +0x30 of the class whose vtable is at
 * 0x16d3b98 (leaf_013d66e0.cpp). Every name here is derived. */
#ifndef TLG_GAME_OBJECT013D6840_H
#define TLG_GAME_OBJECT013D6840_H

#include "tlg_types.h"
#include "tlg_game_array.h"

/* derived names: the class of the vtable at 0x16d3b70
 * (config/vtables.derived.base.txt): its destructor (FUN_013d6840) stores
 * the vtable and releases the block the pointer at +0x18 holds
 * (tlg_game_block.h). The destructor is the class's key function, so
 * leaf_013d6840.cpp emits the vtable. The other members are not traced. */
class Object013d6840 /* derived name */
{
  public:
    virtual ~Object013d6840();

    /* slot 2 (FUN_013d4870): the values made 72 zeros, the block reallocated
     * to exactly 72 when the capacity differs */
    virtual void reset(); /* derived name */

  private:
    u8 unknown8[0x10];
    Array05943280<u32> values18; /* +0x18: owned by the object, released by the destructor */
};

#endif

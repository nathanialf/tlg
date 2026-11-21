/* src/include/tlg_game_object013da160.h: the class whose vtable is at
 * 0x16d3be0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT013DA160_H
#define TLG_GAME_OBJECT013DA160_H

#include "tlg_types.h"
#include "tlg_game_array.h"

/* derived names: the class whose vtable is at 0x16d3be0
 * (config/vtables.derived.base.txt); its complete destructor FUN_013da160
 * (leaf_013da160.cpp) stores the vtable and releases the array at
 * +0x18 (its block, tlg_game_block.h); the class whose destructor is
 * 0xf71430 holds one at +0x460 and has it inlined (`mov [r14+0x460],
 * vtable` and the block at +0x478). The other members are not traced. */
class Object013da160 /* derived name */
{
  public:
    virtual ~Object013da160();

    /* slot 2 (FUN_013d7350): the values made 44 zeros, the block reallocated
     * to exactly 44 when the capacity differs */
    virtual void reset(); /* derived name */

  private:
    u8 unknown8[0x10];
    Array05943280<u32> values18; /* +0x18: owned by the object, released by the destructor */
};

#endif

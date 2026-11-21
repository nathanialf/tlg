/* src/include/tlg_game_object013ef2e0.h: the class whose vtable is at
 * 0x16d51b8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT013EF2E0_H
#define TLG_GAME_OBJECT013EF2E0_H

#include "tlg_types.h"
#include "tlg_game_array.h"

/* derived names: the class whose vtable is at 0x16d51b8
 * (config/vtables.derived.base.txt); its complete destructor FUN_013ef2e0
 * (leaf_013ef2e0.cpp) stores the vtable and releases the array at
 * +0x18 (its block, tlg_game_block.h); the class whose destructor is
 * 0x1006120 holds one at +0x308 and has it inlined (`mov [r14+0x308],
 * vtable` and the block at +0x320). The other members are not traced. */
class Object013ef2e0 /* derived name */
{
  public:
    virtual ~Object013ef2e0();

    /* slot 2 (FUN_013ed770, the same body as Object013d2f90's, one copy in the executable): the values made 36 zeros, the block reallocated
     * to exactly 36 when the capacity differs */
    virtual void reset(); /* derived name */

  private:
    u8 unknown8[0x10];
    Array05943280<u32> values18; /* +0x18: owned by the object, released by the destructor */
};

#endif

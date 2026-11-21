/* src/include/tlg_game_object013d2f90.h: the class whose vtable is at
 * 0x16d3868 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT013D2F90_H
#define TLG_GAME_OBJECT013D2F90_H

#include "tlg_types.h"
#include "tlg_game_array.h"

/* derived names: the class whose vtable is at 0x16d3868
 * (config/vtables.derived.base.txt): its destructor (FUN_013d2f90,
 * leaf_013d2f90.cpp) releases the array it holds at +0x18. Also a member at
 * +0x10 of the classes whose vtables are 0x16bf020 and 0x16c1e40. The other
 * members are not traced. */
class Object013d2f90 /* derived name */
{
  public:
    virtual ~Object013d2f90();

    /* slot 2 (FUN_013ed770, the body Object013ef2e0's slot 2 shares): the values made 36 zeros, the block reallocated
     * to exactly 36 when the capacity differs */
    virtual void reset(); /* derived name */

  private:
    u8 unknown8[0x10];
    Array05943280<u32> values18; /* +0x18: owned by the object, released by the destructor */
};

#endif

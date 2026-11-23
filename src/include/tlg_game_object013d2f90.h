/* src/include/tlg_game_object013d2f90.h: the class whose vtable is at
 * 0x16d3868 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT013D2F90_H
#define TLG_GAME_OBJECT013D2F90_H

#include "tlg_types.h"
#include "tlg_game_array01343a80.h"

/* derived names: the class whose vtable is at 0x16d3868
 * (config/vtables.derived.base.txt): its destructor (FUN_013d2f90,
 * leaf_013d2f90.cpp) releases the array it holds at +0x18. Also a member at
 * +0x10 of the classes whose vtables are 0x16bf020 and 0x16c1e40. The other
 * members are not traced. */
class Object013d2f90 /* derived name */
{
  public:
    /* the pointer at +0x8 made the object's own array, the ints after the
     * array set, then the values made 36 zeros as slot 2 makes them, in
     * line in the holders' constructors (FUN_0120fe90 and FUN_00f4cf00: the
     * stores up to +0x40 of the member before the reallocation; a call of
     * the slot stays a call through the vtable, read again after the
     * lock's release) */
    Object013d2f90()
        : current(&values18), unknown10(0), unknown30(0), unknown34(0), unknown38(-1), unknown3c(1),
          unknown40(0)
    {
        zeroValues();
    }

    virtual ~Object013d2f90();

    /* slot 2 (FUN_013ed770, the body Object013ef2e0's slot 2 shares): the values made 36 zeros, the block reallocated
     * to exactly 36 when the capacity differs */
    virtual void reset(); /* derived name */

  private:
    /* the values made 36 zeros, the block reallocated to exactly 36 when
     * the capacity differs */
    void zeroValues() /* derived name */
    {
        values18.resize(36);
        for (unsigned i = 0; i < values18.size(); ++i)
            values18[i] = 0;
    }

    Array01343a80<u32> *current; /* +0x8: the array at +0x18 */
    int unknown10;               /* +0x10 */
    Array01343a80<u32> values18; /* +0x18: owned by the object, released by the destructor */
    int unknown30;               /* +0x30 */
    int unknown34;               /* +0x34 */
    int unknown38;               /* +0x38: -1 from the constructor */
    int unknown3c;               /* +0x3c: 1 from the constructor */
    void *unknown40;             /* +0x40 */
};

#endif

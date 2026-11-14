/* src/include/tlg_game_array01343a80.h: an array with a state word (game
 * region; docs/TARGETS.md). derived names throughout. The block at +0x0, the
 * count at +0x8, the capacity at +0xc and the owner's index at +0x10 are the
 * growable array's (tlg_game_array.h); the int at +0x14 is put back from 1
 * to 0 by compare-and-swap when the holder is emptied (FUN_01343a80: three
 * of them at +0x10, +0x28 and +0x48 of the holder, 0x18 bytes each). */
#ifndef TLG_GAME_ARRAY01343A80_H
#define TLG_GAME_ARRAY01343A80_H

#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_node.h"

template <class T> class Array01343a80 : public Array05943280<T> /* derived name */
{
  public:
    void release() /* derived name */
    {
        compareAndSwap(&state, 1, 0);
    }

  private:
    int state; /* +0x14 */
};

#endif

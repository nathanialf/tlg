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
    /* the state released after the array is made empty (0x12adade, 0xc1acc0:
     * `mov dword [rbp-0x3c], 0` after the index's store at +0x10). The word
     * is a lock's (release() below gives it back by compare-and-swap) and
     * its first store is the lock's release, an atomic store, not a plain
     * one: where a class holds two arrays the first's word stays a store of
     * its own before the second's fields are cleared (0x995609: `mov dword
     * [r15+0x3c], 0` then `vmovdqu [r15+0x40], xmm0`), and a plain zero
     * store there joins the zero stores after it in one 20-byte clear. */
    Array01343a80()
    {
        __sync_lock_release(&state);
    }

    void release() /* derived name */
    {
        compareAndSwap(&state, 1, 0);
    }

  private:
    int state; /* +0x14 */
};

#endif

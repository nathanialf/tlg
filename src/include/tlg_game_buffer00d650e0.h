/* src/include/tlg_game_buffer00d650e0.h: a buffer member of two classes
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_BUFFER00D650E0_H
#define TLG_GAME_BUFFER00D650E0_H

#include "tlg_types.h"
#include "tlg_game_block.h"

/* derived names: a buffer member: its block at +0x0, a count at +0x8, flags
 * at +0xc (bit 0: the block is not its own; bit 4 survives a reset) and an
 * int at +0x10. Its destructor resets it. Members at +0x50
 * of the class whose destructor is 0xd650e0 and at +0x58 of the one whose
 * destructor is 0xe97590. */
struct Buffer00d650e0 { /* derived name */

    ~Buffer00d650e0()
    {
        reset();
    }

    /* releases an owned block and resets the rest; a holder may reset it
     * before its destructor runs (0x13b9950: the stores twice) */
    void reset() /* derived name */
    {
        if (!(flags & 1))
            releaseBlock(block);
        block = 0;
        count = 0;
        flags &= 0x10;
        unknown10 = 0;
    }

    void *block;    /* +0x0 */
    int count;      /* +0x8 */
    unsigned flags; /* +0xc */
    int unknown10;  /* +0x10 */
};

#endif

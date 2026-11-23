/* src/include/tlg_game_frame.h: two vectors the game keeps together, the
 * first zero and the second the w axis from the constructor (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_FRAME_H
#define TLG_GAME_FRAME_H

#include "tlg_simd.h"
#include "tlg_game_vector.h"

/* derived names: the constructor stores the cleared register, then the
 * including unit's own VECTOR_W, read again after every store before it
 * (FUN_010644d0: `vmovaps [rbx+0x250], xmm1` of the cleared register, then
 * the unit's VECTOR_W at +0x260; the element constructors of FUN_013d28a0,
 * FUN_013fb310 and FUN_013fa8d0). Not traced further. */
struct Frame016c1128 { /* derived name */

    Frame016c1128() : unknown0(_mm_setzero_ps()), unknown10(VECTOR_W.v) {}

    /* back to what the constructor makes, stored in the same order, the
     * unit's VECTOR_W read after the zero is stored (FUN_01353240) */
    void reset() /* derived name */
    {
        unknown0 = _mm_setzero_ps();
        unknown10 = VECTOR_W.v;
    }

    Vec4 unknown0;  /* +0x0: zero from the constructor */
    Vec4 unknown10; /* +0x10: VECTOR_W from the constructor */
};

#endif

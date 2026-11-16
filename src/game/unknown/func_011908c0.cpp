/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_frames013fb310.h"
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_011908c0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 2 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad5500(D_15cb5dd, false);
Name D_5ad5504(D_15cb5e6, false);

/* derived names: 0x70 bytes, 16-byte aligned: three pairs of a vector set to
 * zero and one set to this unit's VECTOR_W, then a pointer cleared, by the
 * default constructor (Element0140d5c0 of func_010ef520.cpp, over this
 * unit's VECTOR_W); not traced further. */
struct Element01449630 { /* derived name */

    Element01449630()
        : unknown0(_mm_setzero_ps()), unknown10(VECTOR_W.v), unknown20(_mm_setzero_ps()),
          unknown30(VECTOR_W.v), unknown40(_mm_setzero_ps()), unknown50(VECTOR_W.v), unknown60(0)
    {
    }

    Vec4 unknown0;   /* +0x0 */
    Vec4 unknown10;  /* +0x10 */
    Vec4 unknown20;  /* +0x20 */
    Vec4 unknown30;  /* +0x30 */
    Vec4 unknown40;  /* +0x40 */
    Vec4 unknown50;  /* +0x50 */
    void *unknown60; /* +0x60 */
};

/* derived name: sets the count of an array of them (tlg_game_array.h's
 * resize). Called from 3 sites in 2 functions (FUN_01175460, FUN_01449250). */
void FUN_01449630(Array05943280<Element01449630> *array, unsigned size) /* derived name */
{
    array->resize(size);
}

/* derived name: this file's frame entry (tlg_game_frames013fb310.h): one
 * element type per file, as the base holds one resize of them per file */
struct FrameEntry011908c0 : FrameEntry013fb310 { /* derived name */
};

/* FUN_01449940 */
template void Array05943280<FrameEntry011908c0>::resize(unsigned);

/* derived name: this file's frame set (tlg_game_frames013fb310.h) */
struct FrameSet011908c0 : FrameSet013fa8d0 { /* derived name */
    FrameSet011908c0();
};

/* FUN_01449170 */
FrameSet011908c0::FrameSet011908c0()
{
    frames.resize(4);
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_frames013fb310.h"
#include "tlg_game_name.h"
#include "tlg_game_vector.h"
#include "tlg_game_object0140dc00.h"

/* derived names: FUN_010ef520 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 2 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad2850(D_15cb5dd, false);
Name D_5ad2854(D_15cb5e6, false);

/* derived names: 0x70 bytes, 16-byte aligned: three pairs of a vector set to
 * zero and one set to this unit's VECTOR_W, then a pointer cleared, by the
 * default constructor; not traced further. */
struct Element0140d5c0 { /* derived name */

    Element0140d5c0()
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

/* FUN_0140d5c0: sets the count of an array of them (tlg_game_array.h's
 * resize). Called from 3 sites in 2 functions (FUN_010d9730, FUN_0140d390). */
template void Array05943280<Element0140d5c0>::resize(unsigned);

/* derived name: this file's frame entry (tlg_game_frames013fb310.h): one
 * element type per file, as the base holds one resize of them per file */
struct FrameEntry010ef520 : FrameEntry013fb310 { /* derived name */
};

/* FUN_0140d8d0 */
template void Array05943280<FrameEntry010ef520>::resize(unsigned);

/* derived name: this file's frame set (tlg_game_frames013fb310.h) */
struct FrameSet010ef520 : FrameSet013fa8d0 { /* derived name */
    FrameSet010ef520();
};

/* FUN_0140d2b0 */
FrameSet010ef520::FrameSet010ef520()
{
    frames.resize(4);
}

/* derived name: FUN_010ef6e0 makes every frame set of a poser (tlg_game_frames013fb310.h)
 * 3 frames long, the array's resize in line with this file's VECTOR_W (its
 * callers FUN_010d9730 and FUN_010dbbd0 are not written) */
void FUN_010ef6e0(FramePoser013fccf0 *self) /* derived name */
{
    for (unsigned i = 0; i < self->count; ++i)
        self->sets.at(i).frames.resize(3);
}

/* FUN_01411be0: FUN_013ef390's body (func_0101dcc0.cpp) with this file's VECTOR_W */
Object016d5a48::Object016d5a48(unsigned count) : model(0), count(count)
{
    values10.resize(count);
    sets28.resize(count);
    frames40.resize(count);
    values80.resize(count);
    for (u8 key = 0; key < count; ++key) {
        values10[key] = 0;
        values80[key] = 0;
        frames40[key].unknown0 = _mm_setzero_ps();
        frames40[key].resetSecond();
    }
}

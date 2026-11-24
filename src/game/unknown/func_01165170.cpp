/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_frames013fb310.h"
#include "tlg_game_name.h"
#include "tlg_game_vector.h"
#include "tlg_game_object0143e060.h"

/* derived names: FUN_01165170 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 2 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad46e0(D_15cb5dd, false);
Name D_5ad46e4(D_15cb5e6, false);

/* derived names: 0x70 bytes, 16-byte aligned: three pairs of a vector set to
 * zero and one set to this unit's VECTOR_W, then a pointer cleared, by the
 * default constructor (Element0140d5c0 of func_010ef520.cpp, over this
 * unit's VECTOR_W); not traced further. */
struct Element0143db70 { /* derived name */

    Element0143db70()
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

/* FUN_0143db70: sets the count of an array of them (tlg_game_array.h's
 * resize). Called from 3 sites in 2 functions (FUN_0114db30, FUN_0143d790). */
template void Array05943280<Element0143db70>::resize(unsigned);

/* derived name: this file's frame entry (tlg_game_frames013fb310.h): one
 * element type per file, as the base holds one resize of them per file */
struct FrameEntry01165170 : FrameEntry013fb310 { /* derived name */
};

/* FUN_0143de80 */
template void Array05943280<FrameEntry01165170>::resize(unsigned);

/* derived name: this file's frame set (tlg_game_frames013fb310.h) */
struct FrameSet01165170 : FrameSet013fa8d0 { /* derived name */
    FrameSet01165170();
};

/* FUN_0143df80 */
FrameSet01165170::FrameSet01165170()
{
    frames.resize(4);
}

/* FUN_01442270: FUN_013ef390's body (func_0101dcc0.cpp) with this file's VECTOR_W */
Object016d5fb0::Object016d5fb0(unsigned count) : model(0), count(count)
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

/* derived name: FUN_013e5560's body (func_00fda5c0.cpp) with this file's
 * VECTOR_W: every frame set of the poser made `count` frames long */
// The base's loop is split on the frame count being 0 by the unit pipeline's
// LoopUnswitch (tools/patches/llvm-3.7.1-unswitch-01-whole-invariant-branch.patch).
void FUN_0143d9c0(FramePoser013fccf0 *self, int count) /* derived name */
{
    for (unsigned i = 0; i < self->count; ++i)
        self->sets.at(i).frames.resize(count);
}

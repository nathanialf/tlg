/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_frames013fb310.h"
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

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

/* derived name: sets the count of an array of them (tlg_game_array.h's
 * resize). Called from 3 sites in 2 functions (FUN_0114db30, FUN_0143d790). */
void FUN_0143db70(Array05943280<Element0143db70> *array, unsigned size) /* derived name */
{
    array->resize(size);
}

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

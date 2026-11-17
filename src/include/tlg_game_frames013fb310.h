/* src/include/tlg_game_frames013fb310.h: the frame records of the eight
 * files whose resize FUN_013fb310 is (game region; docs/TARGETS.md). Every
 * name here is derived. */
#ifndef TLG_GAME_FRAMES013FB310_H
#define TLG_GAME_FRAMES013FB310_H

#include "tlg_game_array.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_fade013d2490.h"
#include "tlg_game_frame.h"

/* derived names: 0x90 bytes, four frames and an int cleared after them, in
 * member order (FUN_013fb310 and its seven copies, one per file: the
 * elements built from the file's own VECTOR_W) */
struct FrameEntry013fb310 { /* derived name */

    FrameEntry013fb310() : unknown80(0) {}

    Frame016c1128 frames[4]; /* +0x0 */
    int unknown80;           /* +0x80 */
};

/* derived names: an array of frames with its lock, made four frames long by
 * its constructor (FUN_013fa8d0 and its six copies, one per file: the
 * array's and the lock's constructors, then the resize to 4 with the frames
 * built from the file's own VECTOR_W) */
struct FrameSet013fa8d0 {                /* derived name */
    Array01343a80<Frame016c1128> frames; /* +0x0 */
};

/* derived names: an array of vectors, one per frame (FUN_01404660 and its
 * copies: a pose's vector at +0x20 copied into one) */
struct VectorSet01404660 {          /* derived name */
    Array01343a80<Vector4> vectors; /* +0x0 */
};

/* derived names: an object holding a frame set per pose of a model: the
 * model at +0x8, each set's pose index (an array at +0x10), the sets (an
 * array at +0x28) and their count at +0x98 (FUN_013fccf0 and its copies,
 * one per file: an unsigned counter passed to at(int), each element's
 * index sign-extended in the loop) and a vector set per pose at +0xa0
 * (FUN_01404660 and its copies) */
struct FramePoser013fccf0 { /* derived name */
    u8 unknown0[0x8];
    FadeModel013d4610 *model;             /* +0x8 */
    Array05943280<int> indices;           /* +0x10 */
    Array05943280<FrameSet013fa8d0> sets; /* +0x28 */
    u8 unknown40[0x58];
    unsigned count; /* +0x98 */
    u8 unknown9c[0x4];
    Array05943280<VectorSet01404660> vectorSets; /* +0xa0 */
};

#endif

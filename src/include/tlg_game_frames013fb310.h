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

/* derived name: the frame set of func_00fda5c0.cpp, its two frames made
 * with that file's VECTOR_W by its constructor (FUN_013e72e0, out of line
 * there); the lists of the track classes' constructors (FUN_013ef390 and
 * nineteen more) are an array of it, sized by FUN_013e71b0 */
struct FrameSet00fda5c0 : FrameSet013fa8d0 { /* derived name */
    FrameSet00fda5c0();
};

/* derived name: a vector its constructor makes zero (the elements of the
 * first set of FrameRecord013ef6b0) */
struct ZeroVector013ef6b0 { /* derived name */

    ZeroVector013ef6b0() : v(_mm_setzero_ps()) {}

    Vec4 v;
};

/* derived names: 0x70 bytes, a frame, an array of vectors and an array of
 * frames, each made two long by the constructor of each file's copy, then
 * two vectors made zero (FUN_013ef6b0, FUN_013f3d10 and FUN_01485320, one
 * per file: the frames built from the file's own VECTOR_W; FUN_01016390
 * makes two at +0x7b0 and +0x820). The frames are an array of the record's
 * own, not a FrameSet013fa8d0: through the set's member the second array's
 * address is folded into its store, where the base keeps it in r14 from
 * before the first array's loop. */
struct FrameRecord013ef6b0 {                   /* derived name */
    Frame016c1128 frame;                       /* +0x0 */
    Array01343a80<ZeroVector013ef6b0> vectors; /* +0x20 */
    Array01343a80<Frame016c1128> frames;       /* +0x38 */
    ZeroVector013ef6b0 unknown50;              /* +0x50 */
    ZeroVector013ef6b0 unknown60;              /* +0x60 */
};

/* derived names: an array of vectors, one per frame (FUN_01404660 and its
 * copies: a pose's vector at +0x20 copied into one) */
struct VectorSet01404660 { /* derived name */
    /* two zero vectors, the capacity made 2 exactly (FUN_013fcc20, out of
     * line: the outer arrays' resize calls it for each set, FUN_0108d540;
     * leaf_013fcc20.cpp) */
    VectorSet01404660();

    Array01343a80<Vector4> vectors; /* +0x0 */
};

/* derived names: an object holding a frame set per pose of a model: the
 * model at +0x8, each set's pose index (an array at +0x10), the sets (an
 * array at +0x28) and their count at +0x98 (FUN_013fccf0 and its copies,
 * one per file: an unsigned counter passed to at(int), each element's
 * index sign-extended in the loop) and an int at +0x9c that the slot 3
 * functions store (FUN_013e7a30, FUN_013e7a50); the classes built on it
 * add their own fields from +0xa0 */
struct FramePoser013fccf0 { /* derived name */
    u8 unknown0[0x8];
    FadeModel013d4610 *model;             /* +0x8 */
    Array05943280<int> indices;           /* +0x10 */
    Array05943280<FrameSet013fa8d0> sets; /* +0x28 */
    u8 unknown40[0x58];
    unsigned count; /* +0x98 */
    int unknown9c;  /* +0x9c */
};

/* derived name: a poser with a vector set per pose at +0xa0 (FUN_01404660
 * and its copies) */
struct VectorPoser01404660 : FramePoser013fccf0 { /* derived name */
    Array05943280<VectorSet01404660> vectorSets;  /* +0xa0 */
};

/* derived name: every frame set of the poser made `count` frames long, with
 * func_0108cf60.cpp's VECTOR_W (FUN_013e5560's body in that file; the tail
 * call of FUN_01404cc0) */
void FUN_013fae50(FramePoser013fccf0 *self, int count); /* derived name */

/* derived name: the same with func_00fda5c0.cpp's VECTOR_W (its definition
 * there); the slot 3 functions of the classes built on the poser end with it
 * (FUN_013e5550, FUN_013e7a30, FUN_013e7a50) */
void FUN_013e5560(FramePoser013fccf0 *self, int count); /* derived name */

#endif

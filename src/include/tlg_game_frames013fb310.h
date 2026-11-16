/* src/include/tlg_game_frames013fb310.h: the frame records of the eight
 * files whose resize FUN_013fb310 is (game region; docs/TARGETS.md). Every
 * name here is derived. */
#ifndef TLG_GAME_FRAMES013FB310_H
#define TLG_GAME_FRAMES013FB310_H

#include "tlg_game_array.h"
#include "tlg_game_array01343a80.h"
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

#endif

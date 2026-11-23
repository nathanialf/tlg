/* src/include/tlg_game_record00fbd1d0.h: the segment two units gather from a
 * fade's skeleton (game region; docs/TARGETS.md): FUN_00faab20 and its copy
 * FUN_0123d660 append them through one append, FUN_00fbd1d0, the link's one
 * copy of the template. Every name here is derived. */
#ifndef TLG_GAME_RECORD00FBD1D0_H
#define TLG_GAME_RECORD00FBD1D0_H

#include "tlg_math.h"

/* derived names: a bone as a segment, its two ends 16-byte aligned points,
 * each copied lane by lane (FUN_00fbd1d0) */
struct Record00fbd1d0 { /* derived name */

    Record00fbd1d0(const Float4A &from_, const Float4A &to_) : from(from_), to(to_) {}

    Float4A from; /* +0x0: the parent's joint */
    Float4A to;   /* +0x10: the joint */
};

#endif

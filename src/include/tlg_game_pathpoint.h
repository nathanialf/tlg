/* src/include/tlg_game_pathpoint.h: a 0x80-byte point of a path the debug
 * views draw (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_PATHPOINT_H
#define TLG_GAME_PATHPOINT_H

#include "tlg_types.h"
#include "tlg_game_object0042dbe0.h"

/* derived names: a point of a path with its free width on each side: the
 * point at +0x0, the two widths at +0x10 and +0x14 (FUN_003df2d0 draws their
 * sum there), and the two edge points at +0x20 and +0x30 (FUN_003deb20 draws
 * each width at its own edge). The rest is not traced. */
struct PathPoint /* derived name */
{
    Position0042dbe0 position; /* +0x0 */
    float leftWidth;           /* +0x10 */
    float rightWidth;          /* +0x14 */
    u8 unknown18[0x8];
    Position0042dbe0 leftEdge;  /* +0x20 */
    Position0042dbe0 rightEdge; /* +0x30 */
    u8 unknown40[0x40];
};

#endif

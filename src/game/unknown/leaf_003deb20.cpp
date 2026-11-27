/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0042dbe0.h"
#include "tlg_game_pathpoint.h"

/* derived names: the object FUN_00315bf0 draws a path for (its debug view of
 * "mainDP", "goalDP", "TurnPt0" and the rest): the debug flags at +0x98, the
 * path's points at +0x68 and their count at +0x70 */
struct PathView00315bf0 /* derived name */
{
    void drawWidths(const PathPoint *point); /* derived name */

    u8 unknown0[0x68];
    PathPoint *points; /* +0x68 */
    int count;         /* +0x70 */
    u8 unknown74[0x24];
    u32 debugFlags; /* +0x98 */
};

/* derived names: FUN_00315bf0 calls it for each point of the path: with
 * flag 1 the two widths drawn at their edges in one colour, with flag 2 in
 * another */
// NONMATCHING: equal under cvtzero-01 (round 578E): under the installed compiler only its four
// conversions differ (`vcvtss2sd xmm0, xmm0, [rbx+0x10]` with no zero before it; the base's
// vxorps xmm0 two to nine instructions ahead): tools/patches/proposed/
// llvm-3.7.1-cvtzero-01-extload-cvtss2sd-zero-passthrough.patch, not installed
void PathView00315bf0::drawWidths(const PathPoint *point)
{
    if (debugFlags & 1) {
        FUN_00205720(point->leftEdge, TextStyle0042dbe0(0x99f4a460, 1.0f), 0, "%.2f",
                     point->leftWidth);
        FUN_00205720(point->rightEdge, TextStyle0042dbe0(0x99f4a460, 1.0f), 0, "%.2f",
                     point->rightWidth);
    }
    if (debugFlags & 2) {
        FUN_00205720(point->leftEdge, TextStyle0042dbe0(0x99ffb6c1, 1.0f), 0, "%.2f",
                     point->leftWidth);
        FUN_00205720(point->rightEdge, TextStyle0042dbe0(0x99ffb6c1, 1.0f), 0, "%.2f",
                     point->rightWidth);
    }
}

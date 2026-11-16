/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_frames013fb310.h"
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_011af640 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 2 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad6150(D_15cb5dd, false);
Name D_5ad6154(D_15cb5e6, false);

/* derived name: this file's frame entry (tlg_game_frames013fb310.h): one
 * element type per file, as the base holds one resize of them per file */
struct FrameEntry011af640 : FrameEntry013fb310 { /* derived name */
};

/* FUN_014613c0 */
template void Array05943280<FrameEntry011af640>::resize(unsigned);

/* derived name: this file's frame set (tlg_game_frames013fb310.h) */
struct FrameSet011af640 : FrameSet013fa8d0 { /* derived name */
    FrameSet011af640();
};

/* FUN_01458990 */
FrameSet011af640::FrameSet011af640()
{
    frames.resize(4);
}

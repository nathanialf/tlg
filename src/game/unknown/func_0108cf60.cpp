/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_frames013fb310.h"
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_0108cf60 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 2 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad10c0(D_15cb5dd, false);
Name D_5ad10c4(D_15cb5e6, false);

/* derived name: this file's frame entry (tlg_game_frames013fb310.h): one
 * element type per file, as the base holds one resize of them per file */
struct FrameEntry0108cf60 : FrameEntry013fb310 { /* derived name */
};

/* FUN_013fb310 */
template void Array05943280<FrameEntry0108cf60>::resize(unsigned);

/* derived name: this file's frame set (tlg_game_frames013fb310.h) */
struct FrameSet0108cf60 : FrameSet013fa8d0 { /* derived name */
    FrameSet0108cf60();
};

/* FUN_013fa8d0 */
FrameSet0108cf60::FrameSet0108cf60()
{
    frames.resize(4);
}

/* derived name: each frame set's first frame takes the model's pose for it,
 * then each set's second frame takes its first, position and rotation */
// NONMATCHING: instruction order only, the first loop's head: the base loads
// the sets' block first (`mov rdx, [rdi+0x28]; movsxd rax, ecx`), the build
// the model first (`mov r10, [rdi+8]`); the IR's order is the base's
void FUN_013fccf0(FramePoser013fccf0 *self) /* derived name */
{
    for (unsigned i = 0; i < self->count; ++i) {
        Frame016c1128 &frame = self->sets.at(i).frames.at(0);
        const int index = self->indices.at(i);
        takePose(frame, self->model, index);
    }
    for (unsigned i = 0; i < self->count; ++i) {
        Array01343a80<Frame016c1128> &frames = self->sets.at(i).frames;
        Frame016c1128 &previous = frames.at(1);
        const Frame016c1128 &current = frames.at(0);
        previous.unknown0 = current.unknown0;
        previous.unknown10 = current.unknown10;
    }
}

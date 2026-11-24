/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_frames013fb310.h"
#include "tlg_game_name.h"
#include "tlg_game_vector.h"
#include "tlg_game_object016d4d28.h"

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

/* FUN_013fae50: FUN_013e5560's body (func_00fda5c0.cpp) with this file's
 * VECTOR_W, slot 3 of the vtable at 0x16d57d0 calling it (leaf_01404cc0.cpp) */
// The base's loop is split on the frame count being 0 by the unit pipeline's
// LoopUnswitch (tools/patches/llvm-3.7.1-unswitch-01-whole-invariant-branch.patch).
void FUN_013fae50(FramePoser013fccf0 *self, int count)
{
    for (unsigned i = 0; i < self->count; ++i)
        self->sets.at(i).frames.resize(count);
}

/* derived name: each frame set's first frame takes the model's pose for it,
 * then each set's second frame takes its first, position and rotation */
// NONMATCHING: instruction order only, the first loop's head: the base loads
// the sets' block first (`mov rdx, [rdi+0x28]; movsxd rax, ecx`), the build
// the model first (`mov r10, [rdi+8]`); the IR's order is the base's.
// Round 500C: the machine scheduler's output is the base's order too (the
// sets' block, the list's data, the model, the indices, the index, the
// table); the order is lost after it, by the registers: the base gives the
// model the sets' block's rdx (dead after the list's load) and the table r10,
// this build the model r10 and the table rbx (the indices' register), and the
// post-RA scheduler then moves the loads. Not traced: what makes the greedy
// allocator take r10 for the model (the 12 copies of this function, 0x13fce60
// to 0x1492ad0, wait on it). Round 555C: the index's order is the base's (not the
// subscript class); the model is local to the loop's block (432 to 576 before
// allocation) and the sets' block's RDX is dead from 416; which range keeps the model
// from it is not traced
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

/* derived name: for each of the five poses, the frame of the frame set and
 * the vector of the vector set at `frame` take the model's pose: its
 * position and its rotation turned to w not negative, then its vector at
 * +0x20; slot 4 of the vtable at 0x16d5670 */
// NONMATCHING: register assignment and order only (59/97, every instruction the base's
// operation): the base keeps the counter in rax and the sets' block in rsi where this has
// rcx and rax, and stores the stack guard before the frame's offsets; an int or unsigned
// counter and the index read before the frame change nothing
void FUN_01404660(VectorPoser01404660 *self, int frame) /* derived name */
{
    for (int i = 0; i < 5; ++i) {
        takePose(self->sets.at(i).frames.at(frame), self->model, self->indices.at(i));
        self->vectorSets.at(i).vectors.at(frame) =
            self->model->skeleton.poses[self->indices.at(i)].unknown20;
    }
}

/* derived name: slot 3 of the vtable at 0x16d5668 (FUN_01404660 is its slot 4): the model kept at +0x8
 * and the int at +0x9c, every frame set made `count` frames long (FUN_013fae50),
 * then each of the five vector sets made `count` vectors long, zero, and
 * every vector set to one (the base splits the five sets' loop on count
 * being 0, docs/DECISIONS.md D92) */
void FUN_01404480(VectorPoser01404660 *self, FadeModel013d4610 *model, int value,
                  unsigned count) /* derived name */
{
    self->model = model;
    self->unknown9c = value;
    FUN_013fae50(self, count);
    for (int i = 0; i < 5; ++i) {
        self->vectorSets.at(i).vectors.resize(count);
        for (unsigned k = 0; k < count; ++k)
            self->vectorSets.at(i).vectors.at(k) = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
    }
}

/* FUN_01400e60: FUN_013ef390's body (func_0101dcc0.cpp) with this file's VECTOR_W */
Object016d56e8::Object016d56e8(unsigned count) : model(0), count(count)
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

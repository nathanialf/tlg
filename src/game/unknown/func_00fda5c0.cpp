/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"
#include "tlg_game_pose013e58c0.h"
#include "tlg_game_frames013fb310.h"

/* derived names: FUN_00fda5c0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 2 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5acf490(D_15cb5dd, false);
Name D_5acf494(D_15cb5e6, false);

/* FUN_013e72e0 */
FrameSet00fda5c0::FrameSet00fda5c0()
{
    frames.resize(2);
}

/* derived name: slot 5 of the vtable at 0x16d4ba0: each of the six bones
 * takes its pose from the model, then keeps its frame as the one before */
void FUN_013e58c0(Poser013e58c0 *self) /* derived name */
{
    for (int i = 0; i < 6; ++i) {
        takePose(self->bones[i].frames->current, self->model, self->indices[i]);
        self->bones[i].frames->keep();
    }
}

/* derived name: slot 6 of the vtable at 0x16d4c20: the same over four bones */
void FUN_013e59f0(Poser013e58c0 *self) /* derived name */
{
    for (int i = 0; i < 4; ++i) {
        takePose(self->bones[i].frames->current, self->model, self->indices[i]);
        self->bones[i].frames->keep();
    }
}

/* derived name: slot 6 of the vtable at 0x16d4ca8: the same over four bones */
void FUN_013e5b20(Poser013e58c0 *self) /* derived name */
{
    for (int i = 0; i < 4; ++i) {
        takePose(self->bones[i].frames->current, self->model, self->indices[i]);
        self->bones[i].frames->keep();
    }
}

/* derived name: makes every frame set of a poser (tlg_game_frames013fb310.h)
 * `count` frames long, the array's resize in line with this file's VECTOR_W
 * (FUN_010ef6e0's body with the count an argument; called by FUN_013e5550,
 * FUN_013e7a30, FUN_013e7a50 and FUN_00fd65c0); the same body, each with
 * its file's VECTOR_W, is FUN_013fae50, FUN_0141ce50, FUN_0143d9c0,
 * FUN_01449480 and FUN_014677a0 (func_0108cf60.cpp, func_0113d440.cpp,
 * func_01165170.cpp, func_011908c0.cpp, func_011c9570.cpp) */
// The base's loop is split on the frame count being 0 by the unit pipeline's
// LoopUnswitch (tools/patches/llvm-3.7.1-unswitch-01-whole-invariant-branch.patch).
void FUN_013e5560(FramePoser013fccf0 *self, int count) /* derived name */
{
    for (unsigned i = 0; i < self->count; ++i)
        self->sets.at(i).frames.resize(count);
}

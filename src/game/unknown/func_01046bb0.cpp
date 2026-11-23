/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"
#include "tlg_game_frames013fb310.h"
#include "tlg_game_pose013e58c0.h"
#include "tlg_game_object016d7a28.h"

/* derived names: FUN_01046bb0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 2 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad05d0(D_15cb5dd, false);
Name D_5ad05d4(D_15cb5e6, false);

/* derived name: slot 5 of the vtable at 0x16d5418: each of the six bones takes
 * its pose from the model, then keeps its frame as the one before
 * (FUN_013e58c0's copy in this file) */
void FUN_013f4370(Poser013e58c0 *self) /* derived name */
{
    for (int i = 0; i < 6; ++i) {
        takePose(self->bones[i].frames->current, self->model, self->indices[i]);
        self->bones[i].frames->keep();
    }
}

/* derived name: this file's frame record (tlg_game_frames013fb310.h), its
 * frames made with this file's VECTOR_W */
struct FrameRecord01046bb0 : FrameRecord013ef6b0 { /* derived name */
    FrameRecord01046bb0();
};

/* FUN_013f3d10 */
FrameRecord01046bb0::FrameRecord01046bb0()
{
    vectors.resize(2);
    frames.resize(2);
}

/* FUN_013f3ee0: FUN_013ef390's body (func_0101dcc0.cpp) with this file's VECTOR_W */
Object016d5498::Object016d5498(unsigned count) : model(0), count(count)
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

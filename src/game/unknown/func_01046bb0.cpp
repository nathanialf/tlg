/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"
#include "tlg_game_pose013e58c0.h"

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

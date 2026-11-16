/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_fade013d2490.h"
#include "tlg_game_name.h"
#include "tlg_game_rotation.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00f6d1a0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 6 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15c541c[25];
extern const char D_15c91d2[10];
extern const char D_15c91dc[10];
extern const char D_15c9538[11];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5acea90(D_15cb5dd, false);
Name D_5acea94(D_15cb5e6, false);
Name D_5ace904(D_15c9538, false);
Name D_5ace908(D_15c91dc, false);
Name D_5ace90c(D_15c91d2, false);
Name D_5ace900(D_15c541c, false);

/* derived name: this file's fade entry (tlg_game_fade013d2490.h): one
 * element type per file, as the base holds one resize of them per file */
struct FadeEntry00f6d1a0 : FadeEntry013d2490 { /* derived name */
};

/* FUN_013d4760 */
template void Array05943280<FadeEntry00f6d1a0>::resize(unsigned);

/* derived name: the fade's entries take their target's rotations (the
 * model's pose for each, +0x10 of a 0x40-byte pose), turned to w not
 * negative, and VECTOR_W at +0x60 */
void FUN_013d4610(Fade013d2490 *self) /* derived name */
{
    self->state = 1;
    FadeTarget013d2490 *target = self->owner->target;
    for (int i = 0; i < target->count; ++i) {
        FadeEntry013d2490 &entry = self->entries[i];
        reinterpret_cast<Vector4 &>(entry.unknown50) =
            self->model->poses[target->unknown28[i]].rotation;
        makeWPositive(entry.unknown50);
        setLanes(entry.unknown60, VECTOR_W);
    }
}

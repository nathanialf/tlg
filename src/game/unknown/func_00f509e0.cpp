/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_fade013d2490.h"
#include "tlg_game_name.h"
#include "tlg_game_rotation.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00f509e0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 19 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15c510e[15];
extern const char D_15c511d[20];
extern const char D_15c5131[20];
extern const char D_15c5145[20];
extern const char D_15c5159[26];
extern const char D_15c5173[24];
extern const char D_15c91d2[10];
extern const char D_15c91dc[10];
extern const char D_15c91e6[20];
extern const char D_15c91fa[19];
extern const char D_15c920d[18];
extern const char D_15c921f[20];
extern const char D_15c9233[19];
extern const char D_15c9246[18];
extern const char D_15c9258[24];
extern const char D_15c9270[23];
extern const char D_15c9287[25];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ace890(D_15cb5dd, false);
Name D_5ace894(D_15cb5e6, false);
Name D_5ace740(D_15c91d2, false);
Name D_5ace744(D_15c91dc, false);
Name D_5ace7a0(D_15c510e, false);
Name D_5ace79c(D_15c511d, false);
Name D_5ace898(D_15c5131, false);
Name D_5ace794(D_15c5145, false);
Name D_5ace798(D_15c5159, false);
Name D_5ace790(D_15c5173, false);
Name D_5ace89c(D_15c91e6, false);
Name D_5ace8a0(D_15c91fa, false);
Name D_5ace8a4(D_15c920d, false);
Name D_5ace8a8(D_15c921f, false);
Name D_5ace8ac(D_15c9233, false);
Name D_5ace8b0(D_15c9246, false);
Name D_5ace7c0(D_15c9258, false);
Name D_5ace7c4(D_15c9270, false);
Name D_5ace7c8(D_15c9287, false);

/* derived name: this file's fade entry. The base holds one resize of an
 * array of fade entries per file (FUN_013d28a0 and its eleven copies, in the
 * linkonce stretch), each building its elements from its own file's VECTOR_W:
 * one element type per file. */
struct FadeEntry00f509e0 : FadeEntry013d2490 { /* derived name */
};

/* FUN_013d28a0 */
template void Array05943280<FadeEntry00f509e0>::resize(unsigned);

/* derived name: this file's copy of FUN_013d4610 (func_00f6d1a0.cpp) */
void FUN_013cf950(Fade013d2490 *self) /* derived name */
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

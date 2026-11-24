/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_names0135c310.h"
#include "tlg_game_vector.h"

/* derived names: the holder FUN_005269a0 empties: an array of records of
 * ten names at +0x28 and an array of vectors at +0x40; the rest is not
 * traced */
struct Holder005a79c0 { /* derived name */
    u8 unknown0[0x28];
    Array05943280<Names0135c310> names28; /* +0x28 */
    Array05943280<Vector4> vectors40;     /* +0x40 */
};

/* FUN_005a79c0: both arrays emptied and their blocks given back */
void FUN_005a79c0(Holder005a79c0 *self) /* derived name */
{
    self->names28.clear();
    self->vectors40.clear();
}

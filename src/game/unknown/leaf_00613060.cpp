/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: the holder FUN_00617960 builds, with an array of pointers
 * at +0x1d0; FUN_00613060 appends one to it (tlg_game_array.h's push, the
 * value passed in a register and stored as it came). Its only caller is
 * FUN_00617960. Neither the holder nor the pointed-to class is traced. */
struct Object00613060; /* derived name */

struct Holder00613060 {                    /* derived name */
    u8 unknown0[0x1d0];                    /* not traced */
    Array05943280<Object00613060 *> items; /* +0x1d0 */
};

void FUN_00613060(Holder00613060 *self, Object00613060 *item) /* derived name */
{
    self->items.push(item);
}

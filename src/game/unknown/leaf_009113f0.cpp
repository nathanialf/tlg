/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: the holder FUN_00908970 builds, with an array of pointers
 * at +0x98; FUN_009113f0 appends one to it (tlg_game_array.h's push, the
 * value passed in a register and stored as it came). Its only caller is
 * FUN_00908970. Neither the holder nor the pointed-to class is traced. */
struct Object009113f0; /* derived name */

struct Holder009113f0 {                    /* derived name */
    u8 unknown0[0x98];                     /* not traced */
    Array05943280<Object009113f0 *> items; /* +0x98 */
};

void FUN_009113f0(Holder009113f0 *self, Object009113f0 *item) /* derived name */
{
    self->items.push(item);
}

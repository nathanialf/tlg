/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"

/* derived names: empties the list of Names at +0x68 counted by the
 * unsigned at +0x70: each Name released (its index cleared), then the count
 * set to 0. The array itself is kept. Class and method unknown. */
struct Object0069bb10 { /* derived name */
    u8 unknown0[0x68];
    Name *names68;    /* +0x68 */
    unsigned count70; /* +0x70 */
};

void FUN_0069bb10(Object0069bb10 *self) /* derived name */
{
    for (unsigned i = 0; i < self->count70; ++i)
        self->names68[i].release();
    self->count70 = 0;
}

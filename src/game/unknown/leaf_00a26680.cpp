/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_creation.h"

/* derived names: FUN_00a26280 with 1 and 0x42000 after the caller's two
 * arguments, under the object's spin lock at +0x24, its result returned
 * (called at 0x1b2f8d). The class, the argument and the two constants'
 * meaning are not traced. */
struct Source00a26280; /* derived name */

struct Object00a26680 { /* derived name */
    u8 unknown0[0x24];
    Lock059458a4 lock; /* +0x24 */
};

int FUN_00a26280(Object00a26680 *self, Source00a26280 *source, int unknown,
                 int flags); /* derived name */

int FUN_00a26680(Object00a26680 *self, Source00a26280 *source) /* derived name */
{
    self->lock.lock();
    int result = FUN_00a26280(self, source, 1, 0x42000);
    self->lock.unlock();
    return result;
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_creation.h"

/* derived names: under the spin lock of the array at +0x288 (its +0x14), empties the array
 * (FUN_013abee0 with 0: its 32-byte elements' blocks given back, the count
 * cleared, the capacity set to the argument) and clears the byte at +0x2b0.
 * The class and the array's elements are not traced. */
struct Array013abee0 { /* derived name: a growable array with its spin lock after its fields */
    u8 unknown0[0x14];
    Lock059458a4 lock; /* +0x14 */
};

struct Object00ca2e40 { /* derived name */
    u8 unknown0[0x288];
    Array013abee0 array; /* +0x288 */
    u8 unknown2a0[0x10];
    bool unknown2b0; /* +0x2b0 */
};

void FUN_013abee0(Array013abee0 *array, unsigned capacity); /* derived name */

void FUN_00ca2e40(Object00ca2e40 *self) /* derived name */
{
    self->array.lock.lock();
    FUN_013abee0(&self->array, 0);
    self->unknown2b0 = false;
    self->array.lock.unlock();
}

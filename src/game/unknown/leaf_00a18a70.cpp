/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: sets the count of the array of ints at +0x88, the new
 * elements zero (tlg_game_array.h's resize); called once, by FUN_001b2f50 */
struct Object00a18a70 { /* derived name */
    u8 unknown0[0x88];
    Array05943280<int> values; /* +0x88 */
};

// NONMATCHING: cookbook 1400's held class: the base reads the allocator (+0x98), the size in
// bytes and D_5943280's address once, after the capacity store and above the block's null
// test; the build puts them in the arms (read before the store, as grow does, the load
// lands above the store)
void FUN_00a18a70(Object00a18a70 *self, unsigned count) /* derived name */
{
    self->values.resize(count);
}

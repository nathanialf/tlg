/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_table01352a50.h"

/* derived name: takes the entry of a name (its index) and hash out of a table
 * of 32 buckets (tlg_game_table01352a50.h); called from 0x72c781, 0x72c865
 * and 0x72c95e. The table's owner is not traced. */
void FUN_0072d130(Table01352a50<32> *self, unsigned name, u32 hash) /* derived name */
{
    self->remove(name, hash);
}

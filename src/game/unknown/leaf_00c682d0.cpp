/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_holder00c682d0.h"

/* FUN_00c682d0: an entry made in a new last slot of the holder's list, when
 * it has one, and counted: its fields set in the slot one by one, the
 * point first and the flag after the count (the base's store order) */
void FUN_00c682d0(Holder00c682d0 *holder, const Shape00c682d0 &shape, int value, float x, float y,
                  float z, float w) /* derived name */
{
    if (Array05943280<Entry00c682d0> *entries = holder->entries) {
        Entry00c682d0 &entry = *entries->append();
        entry.point = Float4A(x, y, z, w);
        entry.shape = shape;
        entry.value = value;
        ++holder->added;
        entry.flag = false;
    }
}

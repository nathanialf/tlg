/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_holder00c682d0.h"

/* FUN_00c68410: FUN_00c682d0's form with the record at +0x68 (called by
 * FUN_00a5ede0 at 0xa62720): an entry made in a new last slot of the
 * holder's list, when it has one, and counted, its fields set in the base's
 * store order, the flag set and the record copied after the count */
void FUN_00c68410(Holder00c682d0 *holder, const Shape00c682d0 &shape, int value,
                  const Extra00c68410 &extra, float x, float y, float z, float w) /* derived name */
{
    if (Array05943280<Entry00c682d0> *entries = holder->entries) {
        Entry00c682d0 &entry = *entries->append();
        entry.point = Float4A(x, y, z, w);
        entry.shape = shape;
        entry.value = value;
        ++holder->added;
        entry.flag = true;
        entry.extra = extra;
    }
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_object016b9108.h"

/* derived names: slot 6 of Object016b78f0 (tlg_game_object016b78f0.h) and
 * of the hundreds of classes over it whose vtables hold 0xc1b350, among
 * them 0x16b7d50 and 0x16b7dd0: the object appends itself to the array of
 * objects it is given (the count raised, the block grown when it is full,
 * by half the count plus one, at most 0x80000 elements a step, then the
 * pointer stored at the old count). Written as a free function as the other
 * slots of unknown classes are; the array's owner is not traced. */
void FUN_00c1b350(Object016b9108 *self, Array05943280<Object016b9108 *> *objects)
{
    objects->push(self);
}

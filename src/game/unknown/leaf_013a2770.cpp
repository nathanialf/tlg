/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d06d0.h"

/* derived name: the constructor (tlg_game_object016d06d0.h): its base
 * Object016b9108 is built from the name passed on, the Name and the arrays
 * start empty; then the body: the ints at +0x30 and +0x28 cleared, each array
 * emptied with a capacity of 0 (its references released one by one, the
 * block reallocated to nothing), the int at +0x68 cleared. */
// NONMATCHING: the whole module calls the arrays' clear (FUN_0138c8d0) where the base inlines it twice (a call kept by the module where the base inlined it, the two-stage question)
Object016d06d0::Object016d06d0(const Name &name) : Object016b9108(name)
{
    unknown30 = 0;
    unknown28 = 0;
    array38.clear(0);
    array50.clear(0);
    unknown68 = 0;
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_object016a96d0.h"

/* derived names: slot 20 of the base class (slot 20 of the vtable at
 * 0x16a9ba8 too), called directly by the override; its class is not traced,
 * so it is typed with the object it is given */
void FUN_00a8e280(Object016a96d0 *self, float step); /* derived name */

/* derived names: with the calling thread's heap replaced by the object's
 * for the call (as slots 13 and 19), the base class's slot 20. */
void Object016a96d0::slot20(float step)
{
    ThreadHeapScope05943280 scope(heap);
    FUN_00a8e280(this, step);
}

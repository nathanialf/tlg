/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b8040.h"

void FUN_00c1a850(Object016b8040 *object); /* derived name; not traced */

/* derived names: the complete destructor FUN_00c1a5e0: FUN_00c1a850 on the
 * object, the array's references released (its block kept), then the
 * members and the base torn down. The class's key function: this unit
 * emits the vtable and the deleting destructor FUN_00c1ac20. */
Object016b8040::~Object016b8040()
{
    FUN_00c1a850(this);
    array30.removeAll();
}

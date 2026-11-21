/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b0408.h"

/* the destructor is the class's key function: this file emits the vtable
 * and the deleting destructor FUN_008e4580 */
Object016b0408::~Object016b0408()
{
    pool.shutdown();
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016c77b8.h"

/* derived name: the complete destructor: slot 5 run first (called
 * directly, as a destructor calls its class's virtuals), then the two
 * references and the name released, last first, and the base's destructor
 * 0x6180c0 tail-called. FUN_00618ae0, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the vtable. */
Object016abea0::~Object016abea0()
{
    FUN_006182f0();
}

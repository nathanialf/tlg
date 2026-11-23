/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016ce0e8.h"

Object016b9108 *FUN_00a05e80(int kind); /* derived name; leaf_00a05e80.cpp */

/* derived name: the constructor (tlg_game_object016ce0e8.h): the three
 * references set in turn to an object FUN_00a05e80 makes of the kind, each
 * by compare-and-swap (`lock cmpxchg qword [r13]` at 0xa05136) */
Object016ce0e8::Object016ce0e8(int kind)
{
    unknown10.set(FUN_00a05e80(kind));
    unknown18.set(FUN_00a05e80(kind));
    unknown20.set(FUN_00a05e80(kind));
}

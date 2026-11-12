/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d0698.h"

/* derived name: the constructor (tlg_game_object016d0698.h): its base
 * Object016b9108 is built from the name passed on, the two Names at +0x24
 * and +0x28 start empty, and the one at +0x28 is set to "_black_texture". */
Object016d0698::Object016d0698(const Name &name) : Object016b9108(name)
{
    texture28 = Name("_black_texture");
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d2d60.h"

/* derived name: the constructor (tlg_game_object016d2d60.h): its base
 * Object016b9108 is built from the name passed on, the fields set, and the
 * Names at +0x8c, +0x90 and +0x94 set to "trico" (looked up, not added) and
 * "data_trico" twice. */
Object016d2d60::Object016d2d60(const Name &name) : Object016b9108(name)
{
    unknown24 = 1;
    unknown28 = 0;
    unknown2c = 1;
    unknown30 = 3;
    width38 = 1920;
    height3c = 1080;
    width40 = 1920;
    height44 = 1080;
    unknown48 = 0;
    unknown4c = 0;
    width50 = 1920;
    height54 = 1080;
    unknown58 = 1;
    unknown5c = 1;
    unknown64 = 0;
    unknown68 = 0;
    unknown34 = 0;
    unknown6c = 1;
    name8c = Name("trico", false);
    name90 = Name("data_trico");
    name94 = Name("data_trico");
}

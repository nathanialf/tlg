/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b8db8.h"

/* derived names: slot 7 of the vtable at 0x16b9048 (its pointer at
 * 0x16b9090): 0 when the object held at +0x40 exists and its ints at +0x50
 * and +0x30 are both set; else the int at +0x50 of the record at +0x38. */
int Object016b9048::slot7() const
{
    if (active())
        return 0;
    return unknown38->unknown50;
}

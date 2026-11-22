/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016aed28.h"

/* derived names: slot 8 of the class at 0x16aed28: the contacts cleared,
 * the name at +0x540 and the int at +0x554 taken as current, bit 17 of the
 * node's flags at +0x24 set (`or byte [rbx+0x26], 2`), and an object with
 * neither end set handed to the world's list as a tail call */
void Object016aed28::slot8()
{
    clearContacts();
    name2cc = name540;
    unknown2c0 = unknown554;
    unknown24 |= 0x20000;
    if (!end238 && !end240)
        FUN_00845600(D_57c9390->list60, this);
}

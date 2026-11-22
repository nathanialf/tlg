/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016aed28.h"

/* derived names: the complete destructor FUN_0083df00 of the class at
 * 0x16aed28 (tlg_game_object016aed28.h): the int at +0x558 and the
 * contacts cleared, then the members torn down, last first (the array of
 * references by 0x134f620, the four names, the table, the name at +0x2cc,
 * the four references), then the node's destructor as a tail call.
 * FUN_0083e350, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. */
Object016aed28::~Object016aed28()
{
    unknown558 = 0;
    clearContacts();
}

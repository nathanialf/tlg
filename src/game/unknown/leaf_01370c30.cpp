/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016cc130.h"

/* derived names: the complete destructor of Object016cc130
 * (tlg_game_object016cc130.h, which says why it is still declared):
 * the body is empty; the Names are released and their block, then the
 * references' destructor FUN_0134f620 out of line, then the root's
 * destructor inlined. */
// NONMATCHING: the deleting destructor FUN_01370d70: the base inlines this complete destructor into it (306 bytes);
// the build calls it (equal with the destructor implicit: the header's OPEN note)
Object016cc130::~Object016cc130() {}

// NONMATCHING: the base inlines Object016cc130's destructor (307 bytes, this unit's) into this one, FUN_01371ea0,
// and keeps the deleting one FUN_01372010 a call; the build calls it (both equal with the destructors implicit:
// the header's OPEN note)
Object016af178::~Object016af178() {}

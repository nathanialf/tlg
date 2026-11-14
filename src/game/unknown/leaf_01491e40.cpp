/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01439e30.h"

/* derived name: the destructor of Object016d7de8 (tlg_game_object01439e30.h):
 * nothing of its own; the members' blocks are released last first, the
 * vtable of each part stored before its members go. */
// NONMATCHING: the two vtables are not defined in the module (the address point is `lea; add 0x10`, the base's
// one `lea`: the classes' key functions are not written), and an inline-cost margin: the base holds the
// destructor of Object016d7dc0 inlined (556 bytes), the build calls it (167 bytes)
Object016d7de8::~Object016d7de8() {}

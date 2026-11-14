/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0140ccc0.h"

/* derived name: the destructor of Object013e8670 (tlg_game_object0140ccc0.h):
 * nothing of its own; the elements' references are released last first,
 * then the reference at +0x18. */
// NONMATCHING: 54/177, 639 bytes for 687, with -disable-preheader-prot (D80); equal (687 bytes) with the
// preheader protection on (round 269C's measurement before D80 landed): a counter-witness to D80 in
// the four unrolled elements and the 24-element loop: to be measured under 3.7.1, which has no protection
Object013e8670::~Object013e8670() {}

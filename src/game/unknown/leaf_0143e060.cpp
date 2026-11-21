/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0143e060.h"

/* derived name: the destructor of Object016d6060 (tlg_game_object0143e060.h):
 * nothing of its own; the members' blocks are released last first, the
 * vtable of each part stored before its members go. */
// NONMATCHING: equal single-file (164 instructions); in the module the part's
// implicit destructor has two callers (this class and the other one over the
// same part) and is called out of line where the base holds it inlined in
// both, and the whole's own vptr store goes (round 399C, two-stage). Lead:
// two part classes whose identical vtables the link merges (ConstantMerge,
// the `merges` row of config/vtables.derived.base.txt), one caller each.
Object016d6060::~Object016d6060() {}

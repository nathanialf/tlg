/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"

/* FUN_004cdb70: the locked array of names copied (called by FUN_004c1910,
 * FUN_004d3fc0, FUN_00616a60, FUN_0073ea20 and FUN_00786cb0: the copy the
 * units share): each name's count raised as it is copied. FUN_008edca0 is
 * a second copy of the same bytes over its own unit's element
 * (leaf_008edca0.cpp). */
template Array01343a80<Name>::Array01343a80(const Array01343a80<Name> &);

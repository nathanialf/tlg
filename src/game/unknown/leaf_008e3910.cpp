/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_object0134f620.h"

/* FUN_008e3910: the locked array of counted references copied (called by
 * FUN_00c6c310, FUN_00c74fd0 and FUN_00cb8d50): each object's count raised
 * as its reference is copied. FUN_00c59f20 and FUN_00f52870 are copies of
 * the same bytes over their own units' elements. */
template Array01343a80<Ref00503fb0<Object016b9108>>::Array01343a80(
    const Array01343a80<Ref00503fb0<Object016b9108>> &);

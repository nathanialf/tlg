/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: FUN_00f2b550 empties an array of counted references and
 * gives its block back (tlg_game_array.h's clear(unsigned)), out of line:
 * every caller passes 0 (the seven table functions of FUN_00f27820's kind),
 * which the link folds in, dropping the argument (no `esi` before any of the
 * 28 calls). Instantiated here, where its callers' unit is not known. The
 * referenced class is not traced. */
class Value00f2b550 : public Object016b9108 /* derived name */
{
};

template void Array05943280<Ref00503fb0<Value00f2b550>>::clear(unsigned);

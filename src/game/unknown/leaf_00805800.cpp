/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: FUN_00805800 empties an array of counted references and
 * gives its block back (tlg_game_array.h's clear), out of line: the array's
 * own member, instantiated here until a caller of it is written. The
 * referenced class is not traced. */
class Value00805800 : public Node00503fb0 /* derived name */
{
};

template void Array05943280<Ref00503fb0<Value00805800>>::clear();

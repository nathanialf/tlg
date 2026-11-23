/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: FUN_005a42c0 appends a counted reference to an array unless
 * the array holds one to the same object (tlg_game_array.h's addUnique),
 * out of line: the array's own member, instantiated here until a caller of
 * it is written (called at 0x5a396d and 0x135c0e5). FUN_002db990 is the same body. The referenced class is
 * not traced. */
class Value005a42c0 : public Object016b9108 /* derived name */
{
};

template void
Array05943280<Ref00503fb0<Value005a42c0>>::addUnique(const Ref00503fb0<Value005a42c0> &);

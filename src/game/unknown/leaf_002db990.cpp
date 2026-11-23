/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: FUN_002db990 appends a counted reference to an array unless
 * the array holds one to the same object (tlg_game_array.h's addUnique),
 * out of line: the array's own member, instantiated here until a caller of
 * it is written (called at 0x2da26c, 0x2da9b1, 0x2daa12). FUN_005a42c0 is the same body. The referenced class is
 * not traced. */
class Value002db990 : public Object016b9108 /* derived name */
{
};

template void
Array05943280<Ref00503fb0<Value002db990>>::addUnique(const Ref00503fb0<Value002db990> &);

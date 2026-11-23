/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: FUN_00d6dd50 appends a counted reference to an array unless
 * the array holds one to the same object (tlg_game_array.h's addUnique),
 * out of line: the array's own member, instantiated here until its callers
 * FUN_00d6c930 and FUN_00d6caf0 are written. FUN_002db990 is the same body. The referenced
 * class is not traced. */
class Value00d6dd50 : public Object016b9108 /* derived name */
{
};

template void
Array05943280<Ref00503fb0<Value00d6dd50>>::addUnique(const Ref00503fb0<Value00d6dd50> &);

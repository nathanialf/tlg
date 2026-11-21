/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: the counted objects of the arrays FUN_00206df0,
 * FUN_002075e0, FUN_00207e70 and FUN_0073ea20 copy (the arrays at +0x58
 * and +0x50 of their holders); not traced */
struct Value00208a00 : Object016b9108 /* derived name */
{};

/* FUN_00208a00 is the copy of an array of counted references to them
 * (tlg_game_array.h's assignment), out of line: the array's own member,
 * instantiated here until a caller of it is written. */
template void Array05943280<Ref00503fb0<Value00208a00>>::operator=(
    const Array05943280<Ref00503fb0<Value00208a00>> &);

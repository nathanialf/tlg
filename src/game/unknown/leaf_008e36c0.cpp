/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* FUN_008e36c0 appends a copy of an array of counted references to an
 * array of such arrays (tlg_game_array.h's push; the copy is
 * Array01343a80's copy constructor, called last: `jmp 0x8e3910`). Called
 * from 3 sites in 1 function (FUN_008e08e0). */
void FUN_008e36c0(Array05943280<Array01343a80<Ref00503fb0<Object016b9108>>> *array,
                  const Array01343a80<Ref00503fb0<Object016b9108>> &value) /* derived name */
{
    array->push(value);
}

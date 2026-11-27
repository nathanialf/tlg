/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b4ce0.h"

/* derived names: appends a reference to one of the guide's arrays
 * (tlg_game_object016b4ce0.h; tlg_game_array.h's push, the growth the
 * header's); the body is FUN_001b59d0's byte for byte. Called from 7 sites
 * in 4 functions (FUN_00b13320, FUN_00b14040, FUN_013904c0, FUN_013907f0). */
void FUN_00b16e40(Array05943280<Ref00503fb0<Object016b9108>> *array,
                  const Ref00503fb0<Object016b9108> &value) /* derived name */
{
    array->push(value);
}

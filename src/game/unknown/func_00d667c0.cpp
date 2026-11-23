/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013baac0.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00d667c0 is this file's static initializer, FUN_00e63c90's
 * bytes (func_00e63c90.cpp). It builds the vector constants of
 * tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then three arrays of counted references
 * (tlg_game_object013baac0.h), each with its owner index from the calling
 * thread's heap and registered with its destructor (0x13baac0), in this
 * order. What reads them is not traced (FUN_00d65170 and the functions after
 * it). */
Object013baac0 D_59497d0;
Object013baac0 D_5949800;
Object013baac0 D_59497e8;

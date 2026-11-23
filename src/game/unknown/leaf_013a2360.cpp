/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_entry013a2360.h"
#include "tlg_game_nametable.h"

/* derived names: the destructor of the table of 32 buckets of
 * tlg_game_entry013a2360.h's entries that FUN_00c1adc0, a static
 * initializer (func_00c1adc0.cpp), registers for the global at 0x5937ec8
 * (lea at 0xc1add7). */

/* FUN_013a2360: with entries left they are emptied, then every block freed */
template NameTable<Entry013a2360, 32>::~NameTable();

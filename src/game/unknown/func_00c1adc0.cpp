/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00c1adc0: the table's three dword stores (32, 24, 0 at 0x5937fd8 to 0x5937fe0) stay three in the base; the build joins the first two into one 8-byte store (DAGCombiner MergeConsecutiveStores), the class of stores to a global noted in round 523D; a volatile count gives the base's bytes and is not taken (nothing shows the program treats it so). */
#include "tlg_game_entry013a2360.h"
#include "tlg_game_nametable.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00c1adc0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then the table of 32 buckets of
 * tlg_game_entry013a2360.h's entries, registered with its destructor
 * (0x13a2360). FUN_00c1a320 and FUN_00c1a850 of this file read it, and
 * FUN_00c36a80 of a later one (none written). */
NameTable<Entry013a2360, 32> D_5937ec8;

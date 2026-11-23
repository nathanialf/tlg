/* src/include/tlg_game_entry013a2360.h: the entry of the table of 32 buckets
 * at 0x5937ec8, FUN_00c1adc0's unit (func_00c1adc0.cpp), whose destructor
 * is FUN_013a2360 (leaf_013a2360.cpp) (game region; docs/TARGETS.md). Every
 * name here is derived. */
#ifndef TLG_GAME_ENTRY013A2360_H
#define TLG_GAME_ENTRY013A2360_H

#include "tlg_types.h"
#include "tlg_game_name.h"

/* derived name: the hash, the name, 8 bytes not traced, the next. The
 * destructor releases the name only; 0x18 bytes (the table's entry size,
 * `mov dword [0x5937fdc], 0x18` at 0xc1af58). */
struct Entry013a2360 { /* derived name */
    u32 hash;          /* +0x0 */
    Name name;         /* +0x4 */
    u8 unknown8[0x8];
    Entry013a2360 *next; /* +0x10 */
};

#endif

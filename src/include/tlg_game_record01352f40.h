/* src/include/tlg_game_record01352f40.h: the records FUN_004bbeb0 deletes
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_RECORD01352F40_H
#define TLG_GAME_RECORD01352F40_H

#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_nametable.h"

/* derived names: one entry of the record's table, 0x18 bytes */
struct Entry01352f40 { /* derived name */
    u32 hash;          /* +0x0 */
    Name name;         /* +0x4 */
    u8 unknown8[0x8];
    Entry01352f40 *next; /* +0x10 */
};

/* derived names: the 64-byte elements of the array at +0xa0, two names
 * after a word */
struct Pair01352f40 { /* derived name */
    u32 unknown0;     /* +0x0 */
    Name name4;       /* +0x4 */
    Name name8;       /* +0x8 */
    u8 unknownc[0x34];
};

/* derived names: the 16-byte elements of the array at +0xb8, a name after
 * a word */
struct Named01352f40 { /* derived name */
    u32 unknown0;      /* +0x0 */
    Name name;         /* +0x4 */
    u8 unknown8[0x8];
};

/* derived names: the records FUN_004bbeb0 deletes, 0xd8 bytes */
struct Record01352f40 { /* derived name */
    ~Record01352f40();

    NameTable<Entry01352f40, 16> table;  /* +0x0 */
    Array05943280<Pair01352f40> pairs;   /* +0xa0 */
    Array05943280<Named01352f40> nameds; /* +0xb8 */
    Name named0;                         /* +0xd0 */
    Name named4;                         /* +0xd4 */
};

#endif

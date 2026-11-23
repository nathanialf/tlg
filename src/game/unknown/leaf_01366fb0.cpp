/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: an entry of the table of 32 buckets at +0x1070 of the
 * object FUN_0072c040 and FUN_00712f40 work on, emptied there through
 * NameTable's clear (the free list at +0x1178, the count at +0x1188), which
 * calls this destructor for each entry (0x72c0e7)
 * and links the entry by +0x40. Four names; the rest not traced. */
struct Entry01366fb0 { /* derived name */
    ~Entry01366fb0();

    u32 hash;  /* +0x0 */
    Name name; /* +0x4 */
    u8 unknown8[0x8];
    Name name10; /* +0x10 */
    Name name14; /* +0x14 */
    Name name18; /* +0x18 */
    u8 unknown1c[0x24];
    Entry01366fb0 *next; /* +0x40 */
};

/* FUN_01366fb0: the names released, the last first */
Entry01366fb0::~Entry01366fb0() {}

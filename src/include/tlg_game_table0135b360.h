/* src/include/tlg_game_table0135b360.h: a table of four names and up to 128
 * name pairs (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_TABLE0135B360_H
#define TLG_GAME_TABLE0135B360_H

#include "tlg_game_name.h"

/* derived names: two names side by side, a slot of the table below */
struct NamePair0135b360 { /* derived name */

    /* both names taken by value, the second stored first (FUN_00c09b10:
     * the copies made first to last, `+0x24` assigned before `+0x20`) */
    void set(Name first, Name second) /* derived name */
    {
        this->second = second;
        this->first = first;
    }

    Name first;  /* +0x0 */
    Name second; /* +0x4 */
};

/* derived names: four names, then 128 slots of name pairs at +0x20 and their
 * count at +0x420. Made by FUN_00c09980 and destroyed by FUN_0135b360, both
 * from FUN_005897a0, FUN_005f2b90 and FUN_00aec5d0; FUN_00c09b10 fills the
 * next slot while fewer than 128 are used. */
struct Table0135b360 { /* derived name */
    Table0135b360();
    ~Table0135b360();

    void add(const Name &second, const Name &first); /* derived name */

    Name name0;                  /* +0x0 */
    Name name4;                  /* +0x4 */
    Name name8;                  /* +0x8 */
    Name namec;                  /* +0xc */
    u32 unknown10;               /* +0x10 */
    u32 unknown14;               /* +0x14 */
    u32 unknown18;               /* +0x18 */
    u32 unknown1c;               /* +0x1c */
    NamePair0135b360 pairs[128]; /* +0x20 */
    unsigned count;              /* +0x420 */
};

#endif

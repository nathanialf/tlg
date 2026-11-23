/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: two names side by side, a slot of the table below */
struct NamePair0135b360 { /* derived name */
    Name first;           /* +0x0 */
    Name second;          /* +0x4 */
};

/* derived names: four names, then 128 slots of name pairs at +0x20 and their
 * count at +0x420 (FUN_00c09b10 fills the next slot while fewer than 128 are
 * used). Destroyed by FUN_005897a0, FUN_005f2b90, FUN_00aec5d0 and
 * FUN_00be79b0. The rest is not traced. */
struct Table0135b360 { /* derived name */
    ~Table0135b360();

    Name name0; /* +0x0 */
    Name name4; /* +0x4 */
    Name name8; /* +0x8 */
    Name namec; /* +0xc */
    u8 unknown10[0x10];
    NamePair0135b360 pairs[128]; /* +0x20 */
    unsigned count;              /* +0x420 */
};

/* FUN_0135b360: the slots released from the last, each pair's second name
 * first, then the four names, the last first */
Table0135b360::~Table0135b360() {}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: a record of nine names from +0xc (FUN_00295010 and
 * FUN_01349f20 destroy it); the first 12 bytes are not traced */
struct Names013490a0 { /* derived name */
    ~Names013490a0();

    u8 unknown0[0xc];
    Name namec;  /* +0xc */
    Name name10; /* +0x10 */
    Name name14; /* +0x14 */
    Name name18; /* +0x18 */
    Name name1c; /* +0x1c */
    Name name20; /* +0x20 */
    Name name24; /* +0x24 */
    Name name28; /* +0x28 */
    Name name2c; /* +0x2c */
};

/* FUN_013490a0: the names released, the last first */
Names013490a0::~Names013490a0() {}

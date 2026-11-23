/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: a record of seven names, 0x1c bytes; the static ones at
 * 0x5ada440, 0x5ada45c, 0x5ada478 and 0x5ada494 are destroyed by
 * FUN_012f58a0, registered at exit (not written). */
struct Names01496780 { /* derived name */
    ~Names01496780();

    Name name0;  /* +0x0 */
    Name name4;  /* +0x4 */
    Name name8;  /* +0x8 */
    Name namec;  /* +0xc */
    Name name10; /* +0x10 */
    Name name14; /* +0x14 */
    Name name18; /* +0x18 */
};

/* FUN_01496780: the names released, the last first */
Names01496780::~Names01496780() {}

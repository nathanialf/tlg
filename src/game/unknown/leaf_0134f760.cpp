/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: a set of five names held at +0x5a8 of the object
 * FUN_003fc620 takes apart and at +0x160 of FUN_00427cc0's, whose destructors
 * call this one. The rest is not traced. */
struct Names0134f760 { /* derived name */
    ~Names0134f760();

    Name name0; /* +0x0 */
    Name name4; /* +0x4 */
    Name name8; /* +0x8 */
    Name namec; /* +0xc */
    u8 unknown10[0x28];
    Name name38; /* +0x38 */
};

/* FUN_0134f760: the names released, the last first */
Names0134f760::~Names0134f760() {}

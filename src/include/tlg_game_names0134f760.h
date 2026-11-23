/* src/include/tlg_game_names0134f760.h: a record of five names and the
 * values between and after them (game region; docs/TARGETS.md). Every name
 * here is derived. */
#ifndef TLG_GAME_NAMES0134F760_H
#define TLG_GAME_NAMES0134F760_H

#include "tlg_types.h"
#include "tlg_game_name.h"

/* derived names: a set of five names held at +0x5a8 of the object
 * FUN_003fc620 takes apart and at +0x50 and +0x160 of FUN_00427cc0's, whose
 * destructors call its destructor (FUN_0134f760, leaf_0134f760.cpp);
 * FUN_00427fb0 and FUN_004282a0 copy the one at +0x50 to +0x160 with set()
 * (FUN_00429690, leaf_00429690.cpp: the implicit assignment, the names one
 * by one, the bytes between them in two copies). The rest is not traced. */
struct Names0134f760 { /* derived name */
    ~Names0134f760();
    void set(const Names0134f760 &other); /* derived name */

    Name name0; /* +0x0 */
    Name name4; /* +0x4 */
    Name name8; /* +0x8 */
    Name namec; /* +0xc */
    u8 unknown10[0x28];
    Name name38; /* +0x38 */
    u8 unknown3c[0x3c];
};

#endif

/* src/include/tlg_game_owner004baab0.h: the object whose named vectors
 * FUN_004baab0 sets (game region; docs/TARGETS.md). Every name here is
 * derived. */
#ifndef TLG_GAME_OWNER004BAAB0_H
#define TLG_GAME_OWNER004BAAB0_H

#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_simd.h"

/* derived names: a named vector, 32 bytes */
struct NamedVector004baab0 { /* derived name */
    Name name;               /* +0x0 */
    u8 unknown4[0xc];
    Vec4 value; /* +0x10 */
};

/* derived names: the object FUN_0046c870 hands FUN_004baab0, its named
 * vectors at +0x5d0, the last one set the most recently */
struct Owner004baab0 { /* derived name */
    void setVector(const Name &name, const Vec4 &value);

    u8 unknown0[0x5d0];
    Array05943280<NamedVector004baab0> vectors; /* +0x5d0 */
};

#endif

/* src/include/tlg_game_format01327490.h: the format the conversions of the
 * table of function pointers at 0x16c94b0 take (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_FORMAT01327490_H
#define TLG_GAME_FORMAT01327490_H

#include "tlg_types.h"

/* derived names: the widths in bits of four packed values (its bytes at +0x6
 * to +0x9). Its other fields are not traced. */
struct Format01327490 { /* derived name */
    u8 unknown0[6];
    u8 bits[4]; /* +0x6 */
};

#endif

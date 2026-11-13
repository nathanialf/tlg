/* src/include/tlg_game_element00343110.h: the 32-byte element of the arrays
 * FUN_00343110 appends to and FUN_003431f0 copies. derived names
 * throughout. Its blocks are allocated 16-aligned (`mov ecx, 0x10` at
 * 0x34317d) and a copy takes the pointer at +0x0 and the four ints at +0x10
 * one by one, never the eight bytes between them (0x3431ac to 0x3431d3). */
#ifndef TLG_GAME_ELEMENT00343110_H
#define TLG_GAME_ELEMENT00343110_H

#include "tlg_types.h"

struct alignas(16) Element00343110 { /* derived name */

    Element00343110(const Element00343110 &other)
        : unknown0(other.unknown0), unknown10(other.unknown10), unknown14(other.unknown14),
          unknown18(other.unknown18), unknown1c(other.unknown1c)
    {
    }

    void *unknown0; /* +0x0 */
    u8 unknown8[8];
    int unknown10; /* +0x10 */
    int unknown14; /* +0x14 */
    int unknown18; /* +0x18 */
    int unknown1c; /* +0x1c */
};

#endif

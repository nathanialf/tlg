/* src/include/tlg_game_element013af390.h: the element of the arrays slots 4
 * and 6 of the vtable at 0x16d1c38 copy and resize (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_ELEMENT013AF390_H
#define TLG_GAME_ELEMENT013AF390_H

#include "tlg_types.h"

/* derived names: ten words, 40 bytes aligned to 4 (`mov ecx, 4` in the
 * reallocation; FUN_013af390's loop of 32-byte and 8-byte zero stores, the
 * copy of FUN_013af280 word by word). The fields are not traced. */
struct Element013af390 { /* derived name */

    Element013af390()
        : unknown0(0), unknown4(0), unknown8(0), unknownc(0), unknown10(0), unknown14(0),
          unknown18(0), unknown1c(0), unknown20(0), unknown24(0)
    {
    }

    u32 unknown0;
    u32 unknown4;
    u32 unknown8;
    u32 unknownc;
    u32 unknown10;
    u32 unknown14;
    u32 unknown18;
    u32 unknown1c;
    u32 unknown20;
    u32 unknown24;
};

#endif

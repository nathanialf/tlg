/* src/include/tlg_game_format012fd300.h: a 32-bit format word whose low eight
 * bits are a kind (game region; docs/TARGETS.md). Every name here is derived.
 * The callers build the word in a 32-bit local and pass its address
 * (0x1a68db: `mov dword [rbp - 0x40], eax; lea rdi, [rbp - 0x40]; call
 * 0x12fd300`), and the kind is compared as a 32-bit value after a one-byte
 * load (0x12fd303: `movzx ecx, byte [rdi]; cmp ecx, 0x3c`): a bit-field of the
 * word, not a byte of its own. The upper 24 bits are not traced. */
#ifndef TLG_GAME_FORMAT012FD300_H
#define TLG_GAME_FORMAT012FD300_H

#include "tlg_types.h"

struct Format012fd300 /* derived name */
{
    u32 kind : 8; /* derived name */
    u32 unknown8 : 24;
};

#endif

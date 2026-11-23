/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: a 40-byte element that owns a block at +0x0 (released when
 * it is destroyed: tlg_game_block.h's OwnedBlock05943280); FUN_013bb300 is
 * the emptying of an array of them to a given capacity (tlg_game_array.h's
 * clear(size)), out of line: the array's own member, instantiated here
 * until a caller of it is written (FUN_00d69cc0, FUN_00d6b0a0). The rest of
 * the element is not traced. */
struct Element013bb300 {      /* derived name */
    OwnedBlock05943280 block; /* +0x0 */
    u8 unknown8[0x20];        /* not traced */
};

template void Array05943280<Element013bb300>::clear(unsigned);

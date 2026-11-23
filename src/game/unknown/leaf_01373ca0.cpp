/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: an element of the array of 0x34-byte records at +0x80 of
 * the object FUN_008e4880 empties (the count at +0x88), destroyed one by one
 * there (`imul rdi, rax, 0x34`) and by four more callers (0x8e6d10, 0x8e7ec0,
 * 0x8e85f0, 0x8ec8b0). Six names; the rest is not traced. */
struct Record01373ca0 { /* derived name */
    ~Record01373ca0();

    u8 unknown0[0x10];
    Name name10; /* +0x10 */
    Name name14; /* +0x14 */
    Name name18; /* +0x18 */
    Name name1c; /* +0x1c */
    u8 unknown20[0xc];
    Name name2c; /* +0x2c */
    Name name30; /* +0x30 */
};

/* FUN_01373ca0: the names released, the last first */
Record01373ca0::~Record01373ca0() {}

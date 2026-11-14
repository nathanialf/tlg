/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a sort comparison whose address FUN_00c68be0 takes (lea at
 * 0xc68ca0): 1 when the 9-bit field at bit 0 of the word at +0x8 of the first
 * record, its top bit flipped (a signed value in offset order), is greater
 * than the second's, else -1. The record type is not traced. */
struct Entry00c68cd0 { /* derived name */
    u8 unknown0[8];
    u32 unknown8 : 9;
    u32 unknown8_9 : 23; /* not traced */
};

int FUN_00c68cd0(const Entry00c68cd0 *a, const Entry00c68cd0 *b) /* derived name */
{
    return (a->unknown8 ^ 0x100) > (b->unknown8 ^ 0x100) ? 1 : -1;
}

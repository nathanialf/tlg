/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_math.h"

/* derived names: the two arrays of an object deleted and their pointers
 * cleared: the 0xb0-byte entries at +0x48 (an array new's count 8 bytes
 * before the first, the block 16 before: the entry is aligned to 16; each
 * entry's counted reference at +0x98 dropped, last entry first), then the
 * array at +0x50 whose elements have no destructor. The entry is the one
 * FUN_00c8b0d0 fills; the owner and the second array's elements are not
 * traced. */
struct Entry00afd570 { /* derived name */
    Float4A unknown0;  /* +0x0 */
    u8 unknown10[0x88];
    Ref00503fb0<Node00503fb0> unknown98; /* +0x98 */
    u8 unknowna0[0x10];
};

struct Object00afd570 { /* derived name */
    u8 unknown0[0x48];
    Entry00afd570 *entries; /* +0x48 */
    u8 *unknown50;          /* +0x50 */
};

// NONMATCHING: the two spill slots' order and nothing else (70/74): the base keeps the object at [rbp-0x30]
// and the block's address at [rbp-0x38], the build the other way round (the frame objects' ordering, held
// without a witness since round 198B)
void FUN_00afd570(Object00afd570 *self) /* derived name */
{
    if (self->entries) {
        delete[] self->entries;
        self->entries = 0;
    }
    if (self->unknown50) {
        delete[] self->unknown50;
        self->unknown50 = 0;
    }
}

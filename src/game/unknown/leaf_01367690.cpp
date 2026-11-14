/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: FUN_013618c0 over the member at +0x1c0, the count at
 * +0x2b8 cleared, then the counted reference of each 16-byte element of
 * the array at +0x298 dropped (the block and the count read again at each
 * one) and its count at +0x2a0 cleared; the block is kept. The owner, the
 * member at +0x1c0 and the elements' first eight bytes are not traced. */
struct Element01367690 { /* derived name */
    u8 unknown0[0x8];
    Ref00503fb0<Node00503fb0> reference; /* +0x8 */
};

struct Member01367690; /* derived name */

struct Object01367690 { /* derived name */
    u8 unknown0[0x1c0];
    u8 unknown1c0[0xd8];
    Array05943280<Element01367690> elements; /* +0x298 */
    u8 unknown2b0[0x8];
    unsigned unknown2b8; /* +0x2b8 */
};

void FUN_013618c0(Member01367690 *member); /* derived name */

// NONMATCHING: a register exchange (59/64; 0x13676d0: the block in rcx and the index in rax, the build has them the other way round)
void FUN_01367690(Object01367690 *self) /* derived name */
{
    FUN_013618c0(reinterpret_cast<Member01367690 *>(self->unknown1c0));
    self->unknown2b8 = 0;
    self->elements.removeAll();
}

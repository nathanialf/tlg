/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: puts an object back to its empty state: FUN_013455b0 on the
 * member at +0x10, the pointer at +0x0 cleared, the float at +0x40 set to -1
 * and the counted reference at +0xa8 emptied by compare-and-swap, then the
 * pointers at +0x90 and +0xb0 cleared and the int at +0x44 set to -1. The
 * owner and its members are not traced further. */
struct Member01345900; /* derived name */

void FUN_013455b0(Member01345900 *member); /* derived name */

struct Object01345900 { /* derived name */
    void *unknown0;     /* +0x0 */
    u8 unknown8[8];
    u8 unknown10[0x30]; /* +0x10: the member FUN_013455b0 works on */
    float unknown40;    /* +0x40 */
    int unknown44;      /* +0x44 */
    u8 unknown48[0x48];
    void *unknown90; /* +0x90 */
    u8 unknown98[0x10];
    AtomicRef0045c470<Node00503fb0> unknowna8; /* +0xa8 */
    void *unknownb0;                           /* +0xb0 */
};

void FUN_01345900(Object01345900 *self) /* derived name */
{
    FUN_013455b0(reinterpret_cast<Member01345900 *>(self->unknown10));
    self->unknown0 = 0;
    self->unknown40 = -1.0f;
    self->unknowna8.clear();
    self->unknown90 = 0;
    self->unknown44 = -1;
    self->unknownb0 = 0;
}

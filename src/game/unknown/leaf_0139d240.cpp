/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: an object put back to empty: the two bytes at +0x1d and
 * +0x1e cleared (one 16-bit store), the counted reference at +0x20 emptied
 * by compare-and-swap, the name at +0xc released, then the pointer at
 * +0x10, the int at +0x18 and the byte at +0x1c cleared. The owner is not
 * traced. */
struct Object0139d240 { /* derived name */
    u8 unknown0[0xc];
    Name name;                                 /* +0xc */
    void *unknown10;                           /* +0x10 */
    int unknown18;                             /* +0x18 */
    u8 unknown1c;                              /* +0x1c */
    u8 unknown1d;                              /* +0x1d */
    u8 unknown1e;                              /* +0x1e */
    AtomicRef0045c470<Node00503fb0> unknown20; /* +0x20 */
};

void FUN_0139d240(Object0139d240 *self) /* derived name */
{
    self->unknown1d = 0;
    self->unknown1e = 0;
    self->unknown20.clear();
    self->name.release();
    self->unknown10 = 0;
    self->unknown18 = 0;
    self->unknown1c = 0;
}

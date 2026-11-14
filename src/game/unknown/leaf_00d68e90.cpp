/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"

/* derived names: empties the object's array of counted references at
 * +0x28 and, when `all` is not zero, the one at +0x40 as well (the blocks
 * kept), then sets bit 0 of the flags at +0x20. The same object as
 * FUN_00d68cf0's (the array at +0x28, the flag); its class is not traced. */
struct Object00d68e90 { /* derived name */
    u8 unknown0[0x20];
    u8 flags20; /* +0x20: bit 0 set when the arrays change */
    u8 unknown21[0x7];
    Array01343a80<Ref00503fb0<Node00503fb0>> unknown28; /* +0x28 */
    Array01343a80<Ref00503fb0<Node00503fb0>> unknown40; /* +0x40 */
};

// NONMATCHING: two instructions in the other order (103/105): at 0xd68f5c the base tests `all` (`cmp dword
// [rbp-0x2c], 0`) before the first array's count is cleared (`mov dword [r15+0x30], 0`), the build after.
void FUN_00d68e90(Object00d68e90 *self, int all) /* derived name */
{
    self->unknown28.removeAll();
    if (all)
        self->unknown40.removeAll();
    self->flags20 |= 1;
}

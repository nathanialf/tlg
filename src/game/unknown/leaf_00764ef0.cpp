/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: when the int at +0x108 of the object is not 0, the counted
 * reference at +0xc10 of the record at +0x68 takes the value of the one at
 * +0x120 of the object, by compare-and-swap; then FUN_00763d70 with both
 * arguments, a tail call. The classes and the second argument are not
 * traced. */
struct Record00764ef0 { /* derived name */
    u8 unknown0[0xc10];
    AtomicRef0045c470<Node00503fb0> unknownc10; /* +0xc10 */
};

struct Object00764ef0 { /* derived name */
    u8 unknown0[0x68];
    Record00764ef0 *unknown68; /* +0x68 */
    u8 unknown70[0x98];
    int unknown108; /* +0x108 */
    u8 unknown10c[0x14];
    AtomicRef0045c470<Node00503fb0> unknown120; /* +0x120 */
};

void FUN_00763d70(Object00764ef0 *self, void *argument); /* derived name */

void FUN_00764ef0(Object00764ef0 *self, void *argument) /* derived name */
{
    if (self->unknown108 != 0)
        self->unknown68->unknownc10 = self->unknown120;
    FUN_00763d70(self, argument);
}

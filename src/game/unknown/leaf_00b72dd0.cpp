/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"

/* derived names: empties what the object holds: the counted references of
 * the array at +0x88 dropped and its count cleared (the block kept), the int
 * at +0x80 cleared and the exchanged reference at +0x78 emptied. Called
 * beside FUN_00b753d0 (0xb73439, 0xb7365a), so most likely a part of the
 * subtitle system; the classes are not traced. */
struct Object00b72dd0 { /* derived name */
    u8 unknown0[0x78];
    AtomicRef0045c470<Node00503fb0> unknown78;          /* +0x78 */
    int unknown80;                                      /* +0x80 */
    Array01343a80<Ref00503fb0<Node00503fb0>> unknown88; /* +0x88 */
};

void FUN_00b72dd0(Object00b72dd0 *self) /* derived name */
{
    self->unknown88.removeAll();
    self->unknown80 = 0;
    self->unknown78.clear();
}

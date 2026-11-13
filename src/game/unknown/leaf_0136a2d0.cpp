/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: drops the counted reference at +0x178, then drops the
 * counted reference at +0xc8 of the object, each pointer cleared first. The
 * owner and the referenced objects' classes are not traced. */
struct Object0136a2d0 { /* derived name */
    u8 unknown0[0xc8];
    Ref00503fb0<Node00503fb0> unknownc8; /* +0xc8 */
    u8 unknownd0[0xa8];
    Ref00503fb0<Node00503fb0> unknown178; /* +0x178 */
};

void FUN_0136a2d0(Object0136a2d0 *self) /* derived name */
{
    self->unknown178.release();
    self->unknownc8.release();
}

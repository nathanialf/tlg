/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: drops the counted reference at +0xc8, then drops the
 * counted reference at +0x18 of the object, each pointer cleared first. The
 * owner and the referenced objects' classes are not traced. */
struct Object013f7ea0 { /* derived name */
    u8 unknown0[0x18];
    Ref00503fb0<Node00503fb0> unknown18; /* +0x18 */
    u8 unknown20[0xa8];
    Ref00503fb0<Node00503fb0> unknownc8; /* +0xc8 */
};

void FUN_013f7ea0(Object013f7ea0 *self) /* derived name */
{
    self->unknownc8.release();
    self->unknown18.release();
}

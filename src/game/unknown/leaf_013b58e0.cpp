/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: drops the counted reference at +0x1e0, then drops the
 * counted reference at +0x1d0 of the object, each pointer cleared first. The
 * owner and the referenced objects' classes are not traced. */
struct Object013b58e0 { /* derived name */
    u8 unknown0[0x1d0];
    Ref00503fb0<Node00503fb0> unknown1d0; /* +0x1d0 */
    u8 unknown1d8[0x8];
    Ref00503fb0<Node00503fb0> unknown1e0; /* +0x1e0 */
};

void FUN_013b58e0(Object013b58e0 *self) /* derived name */
{
    self->unknown1e0.release();
    self->unknown1d0.release();
}

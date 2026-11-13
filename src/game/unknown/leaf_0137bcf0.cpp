/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: drops the counted reference at +0x88, then drops the
 * counted reference at +0x80 of the object, each pointer cleared first. The
 * owner and the referenced objects' classes are not traced. */
struct Object0137bcf0 { /* derived name */
    u8 unknown0[0x80];
    Ref00503fb0<Node00503fb0> unknown80; /* +0x80 */
    Ref00503fb0<Node00503fb0> unknown88; /* +0x88 */
};

void FUN_0137bcf0(Object0137bcf0 *self) /* derived name */
{
    self->unknown88.release();
    self->unknown80.release();
}

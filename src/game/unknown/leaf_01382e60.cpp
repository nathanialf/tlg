/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: drops the counted reference at +0x10, then drops the
 * counted reference at +0x8 of the object, each pointer cleared first. The
 * owner and the referenced objects' classes are not traced. */
struct Object01382e60 { /* derived name */
    u8 unknown0[0x8];
    Ref00503fb0<Node00503fb0> unknown8;  /* +0x8 */
    Ref00503fb0<Node00503fb0> unknown10; /* +0x10 */
};

void FUN_01382e60(Object01382e60 *self) /* derived name */
{
    self->unknown10.release();
    self->unknown8.release();
}

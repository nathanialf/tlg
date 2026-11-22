/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted00818070.h"

/* derived names: the object as FUN_013b7160 sees it: flags at +0x240 and
 * three floats; the rest is not traced */
struct Object013b7160 : Counted00818070 { /* derived name */
    u8 unknown25[0x21b];
    u8 flags240; /* +0x240 */
    u8 unknown241[0xb];
    float unknown24c; /* +0x24c */
    u8 unknown250[0x8];
    float unknown258; /* +0x258 */
    u8 unknown25c[0x9c];
    float unknown2f8; /* +0x2f8 */
};

/* FUN_013b7160: a reference to the object appended to the array
 * (FUN_00818070, called with a temporary reference) when bit 0 of its
 * flags at +0x24 is set, its float at +0x258 is above 1e-5 and either the
 * one at +0x24c is too or, with bit 5 of the flags at +0x240, the one at
 * +0x2f8; returns 1. Its callers are not traced. */
int FUN_013b7160(Object013b7160 *object, Array00818070 *objects) /* derived name */
{
    if ((object->flags24 & 1) && object->unknown258 > 1e-5f &&
        (object->unknown24c > 1e-5f || ((object->flags240 & 0x20) && object->unknown2f8 > 1e-5f)))
        objects->push(Ref00503fb0<Counted00818070>(object));
    return 1;
}

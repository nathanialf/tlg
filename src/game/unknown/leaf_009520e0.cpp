/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted00818070.h"

/* derived names: the object as FUN_009520e0 sees it: an int at +0x21c,
 * flags at +0x240 and a float at +0x258 (FUN_013b7160's object, read
 * here on its own); the rest is not traced */
struct Object009520e0 : Counted00818070 { /* derived name */
    u8 unknown25[0x1f7];
    int unknown21c; /* +0x21c */
    u8 unknown220[0x20];
    u8 flags240; /* +0x240 */
    u8 unknown241[0x17];
    float unknown258; /* +0x258 */
};

/* FUN_009520e0: a reference to the object appended to the array
 * (FUN_00818070, called with a temporary reference) when bit 0 of its
 * flags at +0x24 is set, bit 0 of the flags at +0x240 is not, the int at
 * +0x21c is not zero and the float at +0x258 is above 1e-5; returns 1. Its
 * callers are not traced. */
int FUN_009520e0(Object009520e0 *object, Array00818070 *objects) /* derived name */
{
    if ((object->flags24 & 1) && !(object->flags240 & 1) && object->unknown21c != 0 &&
        object->unknown258 > 1e-5f)
        objects->push(Ref00503fb0<Counted00818070>(object));
    return 1;
}

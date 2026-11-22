/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted00952760.h"

/* derived names: the object as FUN_009521f0 sees it: flags at +0x2a0; the
 * rest is not traced */
struct Object009521f0 : Counted00952760 { /* derived name */
    u8 unknown25[0x27b];
    u8 flags2a0; /* +0x2a0 */
};

/* FUN_009521f0: a reference to the object appended to the array
 * (FUN_00952760, called with a temporary reference) when bit 0 of its
 * flags at +0x24 is set and bit 5 of the flags at +0x2a0 is not; returns 1.
 * Its callers are not traced. */
int FUN_009521f0(Object009521f0 *object, Array00952760 *objects) /* derived name */
{
    if ((object->flags24 & 1) && !(object->flags2a0 & 0x20))
        objects->push(Ref00503fb0<Counted00952760>(object));
    return 1;
}

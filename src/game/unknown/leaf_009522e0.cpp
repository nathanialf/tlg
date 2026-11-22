/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted00952820.h"

extern const Type00503fb0 *D_5945418; /* derived name: the object's type */
extern const Type00503fb0 *D_581fa40; /* derived name: a second type of the object */

/* FUN_009522e0: the object as one of the type at 0x5945418 (null when it
 * is not one): when what its +0x38 points to is set, has a count at +0x30,
 * neither bit 0 nor bit 8 of its flags at +0x38 and a +0x28 whose int at
 * +0x21c is not zero, and the object is also of the type at 0x581fa40, a
 * reference to it is appended to the array (FUN_00952820, called with a
 * temporary reference); returns 1. Its callers are not traced. */
// NONMATCHING: the flag of the first type test, as FUN_00963260's (the
// base: `mov dl, 1` where the walk ends without a match, then `xor ebx, ebx;
// test dl, dl; cmove rbx, rdi`; the build flags the matches), and the order
// of two tests after it (the base tests the +0x28 for null, then the object,
// then the int at +0x21c): 385 bytes for 401.
int FUN_009522e0(Object016b9108 *object, Array00952820 *objects) /* derived name */
{
    Counted00952820 *typed = static_cast<Counted00952820 *>(object);
    if (typed && !typed->isKindOf(D_5945418))
        typed = 0;
    Owner009522e0 *owner = typed->owner38;
    if (owner && owner->unknown30 != 0 && !(owner->flags38 & 0x101)) {
        Object009522e0_28 *unknown28 = owner->unknown28;
        if (unknown28 && object && unknown28->unknown21c != 0 && object->isKindOf(D_581fa40))
            objects->push(Ref00503fb0<Counted00952820>(typed));
    }
    return 1;
}

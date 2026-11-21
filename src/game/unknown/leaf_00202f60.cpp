/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0092cba0.h"
#include "tlg_game_object05945a38.h"

/* derived names: the type the argument is tested for and the type of the
 * object made for it */
extern Type00503fb0 *D_58218a8; /* derived name */
extern Type00503fb0 *D_5820840; /* derived name */

struct Object00202f60; /* derived name */

/* derived names: slot 11 of the vtable at 0x16a7650 (its pointer at
 * 0x16a76b8; the vtable stored by FUN_001bbc30 FUN_00203010): for an object
 * of the type D_58218a8 points to (or one derived from it) an object of the
 * type at 0x5820840 is made under the empty name (FUN_00cbc5a0, mode 0), the
 * argument set as its counted reference at +0x260 (FUN_0092cba0) and its
 * slot 27 called; the made object is returned, else null. self is not used.
 * Class and method unknown. */
Object0092cba0 *FUN_00202f60(Object00202f60 *, Object016b9108 *object) /* derived name */
{
    if (object && object->isKindOf(D_58218a8)) {
        Object0092cba0 *made =
            static_cast<Object0092cba0 *>(FUN_00cbc5a0(D_5945a38, D_5820840, Name(), 0));
        FUN_0092cba0(made, static_cast<Value0092cba0 *>(object));
        made->slot27();
        return made;
    }
    return 0;
}

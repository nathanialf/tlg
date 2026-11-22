/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted00969010.h"

/* derived names: the holder's object at +0x40: slot 9 makes an object from
 * nothing */
struct Maker00963830 : Maker00969010 { /* derived name */
    virtual Counted00969010 *make();   /* derived name; slot 9 */
};

extern const Type00503fb0 *D_58219f8; /* derived name: the maker's type */

/* FUN_00963830: when the holder's object at +0x40 is of the type at
 * 0x58219f8 (or one derived from it), the object its slot 9 makes: a
 * reference to it appended to the record's array (FUN_00969010, called
 * with a temporary reference) and the object kept at +0x28 of the record. */
void FUN_00963830(Holder00963120 *holder, Record00963120 *record) /* derived name */
{
    Maker00969010 *maker = holder->maker40;
    if (maker && maker->isKindOf(D_58219f8)) {
        Counted00969010 *made = static_cast<Maker00963830 *>(maker)->make();
        record->objects.push(Ref00503fb0<Counted00969010>(made));
        record->made28 = made;
    }
}

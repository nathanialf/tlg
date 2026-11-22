/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted00969010.h"

/* derived names: what slot 9 of the holder's object at +0x98 is handed */
struct Arguments00963120 { /* derived name */

    Arguments00963120(void *unknown0_, void *unknown8_) : unknown0(unknown0_), unknown8(unknown8_)
    {
    }

    void *unknown0; /* +0x0: the +0x38 of the record's owner */
    void *unknown8; /* +0x8: the record's +0x8 */
};

/* derived names: the holder's object at +0x98 */
struct Maker00963120 : Maker00969010 {                                 /* derived name */
    virtual Counted00969010 *make(const Arguments00963120 &arguments); /* derived name; slot 9 */
};

extern const Type00503fb0 *D_58207b0; /* derived name: the maker's type */

/* FUN_00963120: when the holder's object at +0x98 is of the type at
 * 0x58207b0 (or one derived from it), the object its slot 9 makes from the
 * record's owner's +0x38 and the record's +0x8: kept at +0x18 of the record
 * and a reference to it appended to the record's array (FUN_00969010,
 * called with a temporary reference). */
void FUN_00963120(Holder00963120 *holder, Record00963120 *record) /* derived name */
{
    Maker00969010 *maker = holder->maker98;
    if (maker && maker->isKindOf(D_58207b0)) {
        Counted00969010 *made = static_cast<Maker00963120 *>(maker)->make(
            Arguments00963120(record->owner->unknown38, record->unknown8));
        record->made18 = made;
        record->objects.push(Ref00503fb0<Counted00969010>(made));
    }
}

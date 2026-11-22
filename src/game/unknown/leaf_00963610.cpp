/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted00969010.h"

/* derived names: what slot 9 of the holder's object at +0x80 is handed */
struct Arguments00963610 { /* derived name */

    Arguments00963610(void *unknown0_, Maker00969010 *maker98_, Maker00969010 *maker78_,
                      void *unknown18_, Counted00969010 *made18_, void *unknown28_)
        : unknown0(unknown0_), maker98(maker98_), maker78(maker78_), unknown18(unknown18_),
          made18(made18_), unknown28(unknown28_)
    {
    }

    void *unknown0;          /* +0x0: the +0x38 of the record's owner */
    Maker00969010 *maker98;  /* +0x8: the holder's +0x98 */
    Maker00969010 *maker78;  /* +0x10: the holder's +0x78 */
    void *unknown18;         /* +0x18: the holder's +0x88 */
    Counted00969010 *made18; /* +0x20: the record's +0x18 */
    void *unknown28;         /* +0x28: the +0x30 of the record's owner */
};

/* derived names: the object made: the base at +0x38 behind the root
 * class's part and 0x14 bytes not traced */
struct Head00963610 : Counted00969010 { /* derived name */
    u8 unknown24[0x14];
};

struct Made00963610 : Head00963610, Part00969010_60 {}; /* derived name */

/* derived names: the holder's object at +0x80 */
struct Maker00963610 : Maker00969010 {                              /* derived name */
    virtual Made00963610 *make(const Arguments00963610 &arguments); /* derived name; slot 9 */
};

extern const Type00503fb0 *D_5821c00; /* derived name: the maker's type */

/* FUN_00963610: when the holder's object at +0x80 is of the type at
 * 0x5821c00 (or one derived from it), the object its slot 9 makes from six
 * values of the holder and the record: a reference to it appended to the
 * record's array (FUN_00969010, called with a temporary reference), the
 * object kept at +0xa8 of the record and its base at +0x38 appended to the
 * array at +0x60. */
void FUN_00963610(Holder00963120 *holder, Record00963120 *record) /* derived name */
{
    Maker00969010 *maker = holder->maker80;
    if (maker && maker->isKindOf(D_5821c00)) {
        Owner00963120 *owner = record->owner;
        Made00963610 *made = static_cast<Maker00963610 *>(maker)->make(
            Arguments00963610(owner->unknown38, holder->maker98, holder->maker78, holder->unknown88,
                              record->made18, owner->unknown30));
        record->objects.push(Ref00503fb0<Counted00969010>(made));
        record->madea8 = made;
        record->parts60.push(made);
    }
}

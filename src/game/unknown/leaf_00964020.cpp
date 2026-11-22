/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted00969010.h"

/* derived names: what slot 9 of the holder's object at +0xa0 is handed */
struct Arguments00964020 { /* derived name */

    Arguments00964020(void *unknown0_, Maker00969010 *maker78_, Owner00963120 *owner_,
                      void *unknown18_, void *unknown20_)
        : unknown0(unknown0_), maker78(maker78_), owner(owner_), unknown18(unknown18_),
          unknown20(unknown20_)
    {
    }

    void *unknown0;         /* +0x0: the +0x38 of the record's owner */
    Maker00969010 *maker78; /* +0x8: the holder's +0x78 */
    Owner00963120 *owner;   /* +0x10: the record's owner */
    void *unknown18;        /* +0x18: the owner's +0x30 */
    void *unknown20;        /* +0x20: the owner's +0x8 */
};

/* derived names: the object made: a base at +0x28 behind the root class's
 * part */
struct Made00964020 : Counted00969010, Part00969010_90 {}; /* derived name */

/* derived names: the holder's object at +0xa0 */
struct Maker00964020 : Maker00969010 {                              /* derived name */
    virtual Made00964020 *make(const Arguments00964020 &arguments); /* derived name; slot 9 */
};

extern const Type00503fb0 *D_5832eb8; /* derived name: the maker's type */

/* FUN_00964020: when the holder's object at +0xa0 is of the type at
 * 0x5832eb8 (or one derived from it), the object its slot 9 makes from
 * five values of the holder and the record's owner: a reference to it
 * appended to the record's array (FUN_00969010, called with a temporary
 * reference), its base at +0x28 appended to the array at +0x90 and the
 * object kept at +0xc8 of the record. */
void FUN_00964020(Holder00963120 *holder, Record00963120 *record) /* derived name */
{
    Maker00969010 *maker = holder->makera0;
    if (maker && maker->isKindOf(D_5832eb8)) {
        Owner00963120 *owner = record->owner;
        Made00964020 *made = static_cast<Maker00964020 *>(maker)->make(Arguments00964020(
            owner->unknown38, holder->maker78, owner, owner->unknown30, owner->unknown8));
        record->objects.push(Ref00503fb0<Counted00969010>(made));
        record->parts90.push(made);
        record->madec8 = made;
    }
}

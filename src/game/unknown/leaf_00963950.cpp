/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted00969010.h"

/* derived names: what slot 9 of each of the holder's objects at +0x48 is
 * handed */
struct Arguments00963950 { /* derived name */

    Arguments00963950(void *unknown0_, Maker00969010 *maker40_, void *unknown10_,
                      Owner00963120 *owner_)
        : unknown0(unknown0_), maker40(maker40_), unknown10(unknown10_), owner(owner_)
    {
    }

    void *unknown0;         /* +0x0: the +0x38 of the record's owner */
    Maker00969010 *maker40; /* +0x8: the holder's +0x40 */
    void *unknown10;        /* +0x10: the holder's +0x88 */
    Owner00963120 *owner;   /* +0x18: the record's owner */
};

/* derived names: the object made: bases at +0x28, +0x40 and +0x50 behind
 * the root class's part, 0x10 and 8 bytes between them not traced */
struct Unknown00963950_30 { /* derived name */
    u8 unknown0[0x10];
};

struct Unknown00963950_48 { /* derived name */
    u8 unknown0[8];
};

struct Made00963950 : Counted00969010,
                      Part00969010_60,
                      Unknown00963950_30,
                      Part00969010_90,
                      Unknown00963950_48,
                      Part00969010_b0 {}; /* derived name */

/* derived names: one of the holder's objects at +0x48 */
struct Maker00963950 : Maker00969010 {                              /* derived name */
    virtual Made00963950 *make(const Arguments00963950 &arguments); /* derived name; slot 9 */
};

/* FUN_00963950: for each of the holder's objects at +0x48 that is set, the
 * object its slot 9 makes from four values of the holder and the record's
 * owner, when it makes one: a reference to it appended to the record's
 * array (FUN_00969010, called with a temporary reference), its base at
 * +0x28 to the array at +0x60, the one at +0x50 to the array at +0xb0, the
 * object itself to the array at +0x48 and its base at +0x40 to the array at
 * +0x90. */
void FUN_00963950(Holder00963120 *holder, Record00963120 *record) /* derived name */
{
    const unsigned count = holder->objects48.size();
    Owner00963120 *owner = record->owner;
    for (unsigned i = 0; i < count; ++i) {
        Maker00963950 *maker = static_cast<Maker00963950 *>(holder->objects48.at(i));
        if (!maker)
            continue;
        Made00963950 *made = maker->make(
            Arguments00963950(owner->unknown38, holder->maker40, holder->unknown88, owner));
        if (!made)
            continue;
        record->objects.push(Ref00503fb0<Counted00969010>(made));
        record->parts60.push(made);
        record->partsb0.push(made);
        record->made48.push(made);
        record->parts90.push(made);
    }
}

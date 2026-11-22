/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted00969010.h"

/* derived names: what slot 9 of the holder's object at +0x78 is handed */
struct Arguments00963260 { /* derived name */

    Arguments00963260(void *unknown0_, void *unknown8_, Maker00969010 *maker98_,
                      Maker00969010 *maker40_, void *unknown20_, void *unknown28_, int flags_)
        : unknown0(unknown0_), unknown8(unknown8_), maker98(maker98_), maker40(maker40_),
          unknown20(unknown20_), unknown28(unknown28_), flags(flags_)
    {
    }

    void *unknown0;         /* +0x0: the +0x38 of the record's owner */
    void *unknown8;         /* +0x8: the owner's +0x30 */
    Maker00969010 *maker98; /* +0x10: the holder's +0x98 */
    Maker00969010 *maker40; /* +0x18: the holder's +0x40 */
    void *unknown20;        /* +0x20: the holder's +0x88 */
    void *unknown28;        /* +0x28: +0x190 of the owner's +0x30 */
    int flags;              /* +0x30: the holder's flags at +0xa8 */
};

/* derived names: the object made: bases at +0x30, +0x38 and +0x40 behind
 * the root class's part and 0xc bytes not traced */
struct Head00963260 : Counted00969010 { /* derived name */
    u8 unknown24[0xc];
};

struct Made00963260 : Head00963260,
                      Part00963260_30,
                      Part00969010_60,
                      Part00969010_78 {}; /* derived name */

/* derived names: the holder's object at +0x78 */
struct Maker00963260 : Maker00969010 {                              /* derived name */
    virtual Made00963260 *make(const Arguments00963260 &arguments); /* derived name; slot 9 */
};

extern const Type00503fb0 *D_5832ff0; /* derived name: the maker's type */
extern const Type00503fb0 *D_58333b0; /* derived name: a type of the holder's objects at +0x48 */

/* FUN_00963260: when the holder's object at +0x78 is of the type at
 * 0x5832ff0 (or one derived from it): for each of the holder's objects at
 * +0x48 the holder's flags at +0xa8 gain 0x10 when the object is of the
 * type at 0x58333b0, else 8, and the flags go to +0x24 of the record's
 * owner; then the object slot 9 makes from seven values of the holder and
 * the owner: a reference to it appended to the record's array
 * (FUN_00969010, called with a temporary reference), the object kept at
 * +0x20 of the record, its bases at +0x38 and +0x40 appended to the arrays
 * at +0x60 and +0x78, and what slot 1 of its base at +0x30 answers stored
 * at +0x18 of the owner. */
// NONMATCHING: the flag of the type test in the loop. The base sets a flag
// where the walk of the types ends without a match (`mov al, 1` before the
// loop's `test rdx, rdx; jne`, `xor eax, eax` on the two matches) and takes
// null on it (`test al, al; cmovne rbx, r9`); the build sets its flag on the
// matches and takes the object (`cmove`): 905 bytes for 934, the rest of
// the function equal around it.
void FUN_00963260(Holder00963120 *holder, Record00963120 *record) /* derived name */
{
    Maker00969010 *maker = holder->maker78;
    if (maker && maker->isKindOf(D_5832ff0)) {
        Owner00963120 *owner = record->owner;
        char *unknown30 = owner->unknown30;
        const unsigned count = holder->objects48.size();
        for (unsigned i = 0; i < count; ++i) {
            Object016b9108 *object = holder->objects48.at(i);
            Object016b9108 *typed = (object && object->isKindOf(D_58333b0)) ? object : 0;
            holder->flagsa8 |= typed ? 0x10 : 0x8;
        }
        owner->flags24 = holder->flagsa8;
        Made00963260 *made = static_cast<Maker00963260 *>(maker)->make(
            Arguments00963260(owner->unknown38, unknown30, holder->maker98, holder->maker40,
                              holder->unknown88, unknown30 + 0x190, holder->flagsa8));
        record->objects.push(Ref00503fb0<Counted00969010>(made));
        record->made20 = made;
        record->parts60.push(made);
        record->parts78.push(made);
        owner->unknown18 = static_cast<Part00963260_30 *>(made)->slot1();
    }
}

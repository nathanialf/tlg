/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16b09f0 (its table without a row): when
 * the object (the second argument) has a target at +0x58 and either of its
 * floats at +0x60 and +0x64 is nonzero, copies the two to +0x130 and +0x134
 * of the target and calls the object's slot 11, a tail call. The first
 * argument is unused; the class and the types beyond their widths are not
 * traced. */
struct Target00900ba0 { /* derived name */
    u8 unknown0[0x130];
    float unknown130; /* +0x130 */
    float unknown134; /* +0x134 */
};

class Object00900ba0 /* derived name */
{
  public:
    virtual void slot0();  /* derived name; not traced */
    virtual void slot1();  /* derived name; not traced */
    virtual void slot2();  /* derived name; not traced */
    virtual void slot3();  /* derived name; not traced */
    virtual void slot4();  /* derived name; not traced */
    virtual void slot5();  /* derived name; not traced */
    virtual void slot6();  /* derived name; not traced */
    virtual void slot7();  /* derived name; not traced */
    virtual void slot8();  /* derived name; not traced */
    virtual void slot9();  /* derived name; not traced */
    virtual void slot10(); /* derived name; not traced */
    virtual void slot11(); /* derived name; not traced */

    u8 unknown8[0x50];
    Target00900ba0 *unknown58; /* +0x58 */
    float unknown60;           /* +0x60 */
    float unknown64;           /* +0x64 */
};

// NONMATCHING: a branch laid out the other way (round 149B's class): the compares are the base's (ordered, one-sided `je`; `!= 0.0f` gives `jne; jp`), but the base falls through to the copy when +0x60 is nonzero and jumps to the test of +0x64, the build the reverse
void FUN_00900ba0(void *, Object00900ba0 *object) /* derived name */
{
    Target00900ba0 *target = object->unknown58;
    if (target == 0)
        return;
    if (object->unknown60 < 0.0f || object->unknown60 > 0.0f || object->unknown64 < 0.0f ||
        object->unknown64 > 0.0f) {
        target->unknown130 = object->unknown60;
        target->unknown134 = object->unknown64;
        object->slot11();
    }
}

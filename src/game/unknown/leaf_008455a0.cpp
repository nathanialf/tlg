/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 6 of the vtable at 0x16aeed0 (its pointer at
 * 0x16aef10; stored by FUN_00844410 and FUN_00844590): for the event 1 with
 * 0, runs FUN_008458e0 on the member at +0x98 and slot 12 of each object of
 * the list at +0xa8 (linked through +0x238); returns 1 always. The event's
 * meaning, the member and the slots are not traced. */
struct Member008455a0; /* derived name */

class Item008455a0 /* derived name */
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
    virtual void slot12(); /* derived name */

    u8 unknown8[0x230];
    Item008455a0 *next238; /* +0x238 */
};

struct Object008455a0 { /* derived name */
    u8 unknown0[0x98];
    Member008455a0 *unknown98; /* +0x98; not traced */
    u8 unknowna0[0x8];
    Item008455a0 *firsta8; /* +0xa8 */
};

void FUN_008458e0(Member008455a0 **member); /* derived name */

// NONMATCHING: the unrotated list loop: the base jumps to the test at the
// bottom (`jmp; ... test rbx, rbx; jne`), this build rotates it and guards it
// at the top (round 149B's question).
int FUN_008455a0(Object008455a0 *self, int event, int value) /* derived name */
{
    if (event == 1 && value == 0) {
        FUN_008458e0(&self->unknown98);
        for (Item008455a0 *item = self->firsta8; item; item = item->next238)
            item->slot12();
    }
    return 1;
}

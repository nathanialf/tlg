/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: drops what the record at +0x370 holds (when its flag at
 * +0x80 is set: slot 7 of the held object with 0, its int at +0x14 and the
 * pointer cleared, then the flag); when the flag at +0x498 is set and the
 * pointer at +0x28 is not null, clears the flag and passes the objects at
 * 0x57d6c3c and 0x57d6b8c and +0xc of the pointed-to object to FUN_004a6bf0
 * (as leaf_00abec40.cpp passes 0x57d6cf4 and 0x57d6b88); calls FUN_00431100
 * with 0 and -1; then, with +0x28 set, hands itself to FUN_00481ec0 on the
 * object at +0x900 of the global's member at +0x38 (when there is one), a
 * tail call. The types are not traced further. */
struct Object057d6c3c; /* derived name */
struct Object057d6b8c; /* derived name */
struct Object00481ec0; /* derived name */

class Held00431030 /* derived name */
{
  public:
    virtual void slot0();            /* derived name; not traced */
    virtual void slot1();            /* derived name; not traced */
    virtual void slot2();            /* derived name; not traced */
    virtual void slot3();            /* derived name; not traced */
    virtual void slot4();            /* derived name; not traced */
    virtual void slot5();            /* derived name; not traced */
    virtual void slot6();            /* derived name; not traced */
    virtual void slot7(int unknown); /* derived name; not traced */

    u8 unknown8[0xc];
    int unknown14; /* +0x14 */
};

struct Record00431030 { /* derived name */
    u8 unknown0[0x78];
    Held00431030 *unknown78; /* +0x78 */
    bool unknown80;          /* +0x80 */
};

struct Object00431030 { /* derived name */
    u8 unknown0[0x28];
    u8 *unknown28; /* +0x28 */
    u8 unknown30[0x340];
    Record00431030 *unknown370; /* +0x370 */
    u8 unknown378[0x120];
    bool unknown498; /* +0x498 */
};

struct Member057c9390_38 { /* derived name */
    u8 unknown0[0x900];
    Object00481ec0 *unknown900; /* +0x900 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x38];
    Member057c9390_38 *unknown38; /* +0x38 */
};

extern Object057c9390 *D_57c9390;
extern Object057d6c3c D_57d6c3c;
extern Object057d6b8c D_57d6b8c;

void FUN_004a6bf0(Object057d6c3c *target, Object057d6b8c *source, void *member); /* derived name */
void FUN_00431100(Object00431030 *self, int unknown1, int unknown2);             /* derived name */
void FUN_00481ec0(Object00481ec0 *target, Object00431030 *self);                 /* derived name */

void FUN_00431030(Object00431030 *self) /* derived name */
{
    Record00431030 *record = self->unknown370;
    if (record->unknown80) {
        Held00431030 *held = record->unknown78;
        if (held) {
            held->slot7(0);
            held->unknown14 = 0;
            record->unknown78 = 0;
        }
        record->unknown80 = false;
    }
    if (self->unknown498 && self->unknown28) {
        self->unknown498 = false;
        FUN_004a6bf0(&D_57d6c3c, &D_57d6b8c, self->unknown28 + 0xc);
    }
    FUN_00431100(self, 0, -1);
    if (self->unknown28) {
        Object00481ec0 *target = D_57c9390->unknown38->unknown900;
        if (target)
            FUN_00481ec0(target, self);
    }
}

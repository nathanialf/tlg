/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 7 of the vtable at 0x16caa98 (address point
 * 0x16caaa8, stored by FUN_0122be10 and FUN_0147ec30; no row: the method
 * stores no vptr), byte for byte FUN_00fb5bd0 (leaf_00fb5bd0.cpp, which
 * describes it): the record's two ints decide the state at +0x58, slot 8's
 * float is kept at +0x60, and 0 is returned when both of the record's
 * floats at +0x90 and +0x1d0 are below 1e-5, else 1. */
struct Record01246f50 { /* derived name */
    u8 unknown0[0x10];
    int unknown10;
    u8 unknown14[0x90 - 0x14];
    float unknown90;
    u8 unknown94[0x150 - 0x94];
    int unknown150;
    u8 unknown154[0x1d0 - 0x154];
    float unknown1d0;
};

struct Holder01246f50 { /* derived name */
    void *unknown0;
    Record01246f50 *record;
};

class Object01246f50 /* derived name */
{
  public:
    virtual ~Object01246f50();
    virtual void slot2();                      /* derived name; not traced */
    virtual void slot3();                      /* derived name; not traced */
    virtual void slot4();                      /* derived name; not traced */
    virtual void slot5();                      /* derived name; not traced */
    virtual void slot6();                      /* derived name; not traced */
    virtual int slot7(Holder01246f50 *holder); /* derived name */
    virtual float slot8();                     /* derived name; not traced */

    u8 unknown8[0x58 - 0x8];
    int state58; /* +0x58: derived name */
    u8 unknown5c[4];
    float unknown60; /* +0x60: slot 8's answer */
};

int Object01246f50::slot7(Holder01246f50 *holder)
{
    Record01246f50 *record = holder->record;
    if (record->unknown10 != 0 || record->unknown150 != 0) {
        if (state58 == 3 || state58 == 0)
            state58 = 1;
    } else if (state58 == 1 || state58 == 2) {
        state58 = 3;
    }
    unknown60 = slot8();
    if (record->unknown90 < 1e-5f && record->unknown1d0 < 1e-5f)
        return 0;
    return 1;
}

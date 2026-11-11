/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 7 of the vtable at 0x16ca608 (address point
 * 0x16ca618, stored by FUN_013e2990 and FUN_013e4200; no row: the method
 * stores no vptr). It reads the record its argument holds at +0x8: while
 * either of the record's ints at +0x10 and +0x150 is set, a state at +0x58
 * of 0 or 3 becomes 1; while both are clear, a state of 1 or 2 becomes 3.
 * It then keeps slot 8's float at +0x60 and returns 0 when both of the
 * record's floats at +0x90 and +0x1d0 are below 1e-5, else 1. FUN_01246f50
 * (leaf_01246f50.cpp, slot 7 of 0x16caa98) has the same bytes. The
 * record's and the states' meaning are not traced. */
struct Record00fb5bd0 { /* derived name */
    u8 unknown0[0x10];
    int unknown10;
    u8 unknown14[0x90 - 0x14];
    float unknown90;
    u8 unknown94[0x150 - 0x94];
    int unknown150;
    u8 unknown154[0x1d0 - 0x154];
    float unknown1d0;
};

struct Holder00fb5bd0 { /* derived name */
    void *unknown0;
    Record00fb5bd0 *record;
};

class Object00fb5bd0 /* derived name */
{
  public:
    virtual ~Object00fb5bd0();
    virtual void slot2();                      /* derived name; not traced */
    virtual void slot3();                      /* derived name; not traced */
    virtual void slot4();                      /* derived name; not traced */
    virtual void slot5();                      /* derived name; not traced */
    virtual void slot6();                      /* derived name; not traced */
    virtual int slot7(Holder00fb5bd0 *holder); /* derived name */
    virtual float slot8();                     /* derived name; not traced */

    u8 unknown8[0x58 - 0x8];
    int state58; /* +0x58: derived name */
    u8 unknown5c[4];
    float unknown60; /* +0x60: slot 8's answer */
};

int Object00fb5bd0::slot7(Holder00fb5bd0 *holder)
{
    Record00fb5bd0 *record = holder->record;
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

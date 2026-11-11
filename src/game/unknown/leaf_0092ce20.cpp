/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16b0e88 (+0xf8 from the vtable stored at
 * 0x16b0d90) and at 0x16c7ad8 (+0xf8 from the one stored at 0x16c79e0): calls
 * the object's slot 24 with 1 (as FUN_009253a0, leaf_009253a0.cpp), then sets
 * bit 7 of its flag byte at +0x24 when the int at +0x280 is 1, or is odd and
 * not 2. The class and the return types are not traced. */
class Object0092ce20 /* derived name */
{
  public:
    virtual void slot0();           /* derived name; not traced */
    virtual void slot1();           /* derived name; not traced */
    virtual void slot2();           /* derived name; not traced */
    virtual void slot3();           /* derived name; not traced */
    virtual void slot4();           /* derived name; not traced */
    virtual void slot5();           /* derived name; not traced */
    virtual void slot6();           /* derived name; not traced */
    virtual void slot7();           /* derived name; not traced */
    virtual void slot8();           /* derived name; not traced */
    virtual void slot9();           /* derived name; not traced */
    virtual void slot10();          /* derived name; not traced */
    virtual void slot11();          /* derived name; not traced */
    virtual void slot12();          /* derived name; not traced */
    virtual void slot13();          /* derived name; not traced */
    virtual void slot14();          /* derived name; not traced */
    virtual void slot15();          /* derived name; not traced */
    virtual void slot16();          /* derived name; not traced */
    virtual void slot17();          /* derived name; not traced */
    virtual void slot18();          /* derived name; not traced */
    virtual void slot19();          /* derived name; not traced */
    virtual void slot20();          /* derived name; not traced */
    virtual void slot21();          /* derived name; not traced */
    virtual void slot22();          /* derived name; not traced */
    virtual void slot23();          /* derived name; not traced */
    virtual void slot24(int value); /* derived name; not traced */

    u8 unknown8[0x1c];
    u8 unknown24;
    u8 unknown25[0x25b];
    int unknown280;
};

// NONMATCHING: switch lowering order, as 0x131f2c0: the base compares 1 then 2, the build 2 then 1 (SelectionDAGBuilder.cpp:8963, the clusters sorted by probability, then the fall-through rearrangement): a compiler-history candidate, not tested
void FUN_0092ce20(Object0092ce20 *self) /* derived name */
{
    self->slot24(1);
    switch (self->unknown280) {
    case 1:
        self->unknown24 |= 0x80;
        break;
    case 2:
        break;
    default:
        if (self->unknown280 & 1) {
            self->unknown24 |= 0x80;
        }
        break;
    }
}

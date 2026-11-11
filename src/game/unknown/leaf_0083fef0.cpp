/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls the object's slot 47 with 0, copies the int at +0x2c0
 * to +0x554 and, when it is positive, clears bit 0 of the byte at +0x4f8; slot
 * 12 of the vtable at 0x16a7a50 (its pointer at 0x16a7ac0), stored by
 * FUN_00297190 and FUN_00297320. The slot's return type and the byte's other
 * bits are not traced. */
class Object0083fef0 /* derived name */
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
    virtual void slot24();          /* derived name; not traced */
    virtual void slot25();          /* derived name; not traced */
    virtual void slot26();          /* derived name; not traced */
    virtual void slot27();          /* derived name; not traced */
    virtual void slot28();          /* derived name; not traced */
    virtual void slot29();          /* derived name; not traced */
    virtual void slot30();          /* derived name; not traced */
    virtual void slot31();          /* derived name; not traced */
    virtual void slot32();          /* derived name; not traced */
    virtual void slot33();          /* derived name; not traced */
    virtual void slot34();          /* derived name; not traced */
    virtual void slot35();          /* derived name; not traced */
    virtual void slot36();          /* derived name; not traced */
    virtual void slot37();          /* derived name; not traced */
    virtual void slot38();          /* derived name; not traced */
    virtual void slot39();          /* derived name; not traced */
    virtual void slot40();          /* derived name; not traced */
    virtual void slot41();          /* derived name; not traced */
    virtual void slot42();          /* derived name; not traced */
    virtual void slot43();          /* derived name; not traced */
    virtual void slot44();          /* derived name; not traced */
    virtual void slot45();          /* derived name; not traced */
    virtual void slot46();          /* derived name; not traced */
    virtual void slot47(int value); /* derived name; not traced */

    u8 unknown8[0x2b8];
    int unknown2c0;
    u8 unknown2c4[0x234];
    bool unknown4f8_0 : 1;
    u8 unknown4f9[0x5b];
    int unknown554;
};

void FUN_0083fef0(Object0083fef0 *self) /* derived name */
{
    self->slot47(0);
    self->unknown554 = self->unknown2c0;
    if (self->unknown554 > 0)
        self->unknown4f8_0 = false;
}

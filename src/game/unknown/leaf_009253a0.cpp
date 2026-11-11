/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16b0e68 (+0xd8 from the vtable stored at
 * 0x16b0d90): calls the object's slot 24 with 1, then in its flags at +0x274
 * sets bit 27 and clears bit 29. The class and the return types are not
 * traced. */
class Object009253a0 /* derived name */
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

    u8 unknown8[0x26c];
    u32 unknown274;
};

void FUN_009253a0(Object009253a0 *self) /* derived name */
{
    self->slot24(1);
    self->unknown274 = (self->unknown274 & ~0x28000000u) | 0x08000000u;
}

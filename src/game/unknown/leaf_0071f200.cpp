/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls its own slot 16 through the vtable, passing its
 * argument on, as a tail call, unless bit 1 of the byte at +0xad4 is set (a
 * one-bit field, cookbook 1111; the slot loaded before the jump, cookbook
 * 1120); slot 12 of the vtable at 0x16ac7c8 (its pointer at 0x16ac838). Class
 * and method unknown. */
class Object0071f200 /* derived name */
{
  public:
    virtual void slot0();                /* derived name; not traced */
    virtual void slot1();                /* derived name; not traced */
    virtual void slot2();                /* derived name; not traced */
    virtual void slot3();                /* derived name; not traced */
    virtual void slot4();                /* derived name; not traced */
    virtual void slot5();                /* derived name; not traced */
    virtual void slot6();                /* derived name; not traced */
    virtual void slot7();                /* derived name; not traced */
    virtual void slot8();                /* derived name; not traced */
    virtual void slot9();                /* derived name; not traced */
    virtual void slot10();               /* derived name; not traced */
    virtual void slot11();               /* derived name; not traced */
    virtual void slot12();               /* derived name; not traced */
    virtual void slot13();               /* derived name; not traced */
    virtual void slot14();               /* derived name; not traced */
    virtual void slot15();               /* derived name; not traced */
    virtual void slot16(void *argument); /* derived name; not traced */
    u8 unknown8[0xad4 - 8];
    u8 unknownad4_0 : 1;
    u8 unknownad4_1 : 1;
};

void FUN_0071f200(Object0071f200 *self, void *argument) /* derived name */
{
    if (!self->unknownad4_1) {
        self->slot16(argument);
    }
}

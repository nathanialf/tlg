/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 10 of the vtables at 0x16a7ea8 and 0x16a7f18: when the
 * int at +0x2b4 is 1 and either the int at +0x29c is zero or bit 5 of the flags
 * at +0x288 is set, returns what the object's slot 11 gives, as a tail call;
 * else 0. Class and methods unknown. */
class Object002b0ef0 /* derived name */
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
    virtual void slot10(); /* derived name; this function */
    virtual int slot11();  /* derived name */

    u8 unknown8[0x280];
    u32 unknown288;
    u8 unknown28c[0x10];
    int unknown29c;
    u8 unknown2a0[0x14];
    int unknown2b4;
};

int FUN_002b0ef0(Object002b0ef0 *self) /* derived name */
{
    if (self->unknown2b4 == 1 && (self->unknown29c == 0 || (self->unknown288 & 0x20))) {
        return self->slot11();
    }
    return 0;
}

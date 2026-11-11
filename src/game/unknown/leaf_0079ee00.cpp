/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_simd.h"

/* derived names: when slot 22 answers nonzero, passes the member at +0x100
 * to FUN_00216780 if its int at +0x8 (+0x108) is set, then copies the rows
 * at +0x13c0 and +0x13e0 of the record at +0x68 into its rows at +0xba0 and
 * +0xb90 (the record read again after each store); the function's pointer
 * is at 0x16adb40 (a vtable without a row). Class and method unknown. */
struct Record0079ee00 { /* derived name */
    u8 unknown0[0xb90];
    Vec4 unknownb90; /* +0xb90 */
    Vec4 unknownba0; /* +0xba0 */
    u8 unknownbb0[0x13c0 - 0xbb0];
    Vec4 unknown13c0; /* +0x13c0 */
    u8 unknown13d0[0x10];
    Vec4 unknown13e0; /* +0x13e0 */
};

struct Member0079ee00 { /* derived name */
    void *unknown0;
    int unknown8; /* +0x8 */
};

void FUN_00216780(Member0079ee00 *member); /* derived name */

class Object0079ee00 /* derived name */
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
    virtual void slot12(); /* derived name; not traced */
    virtual void slot13(); /* derived name; not traced */
    virtual void slot14(); /* derived name; not traced */
    virtual void slot15(); /* derived name; not traced */
    virtual void slot16(); /* derived name; not traced */
    virtual void slot17(); /* derived name; not traced */
    virtual void slot18(); /* derived name; not traced */
    virtual void slot19(); /* derived name; not traced */
    virtual void slot20(); /* derived name; not traced */
    virtual void slot21(); /* derived name; not traced */
    virtual int slot22();  /* derived name; not traced */

    u8 unknown8[0x60];
    Record0079ee00 *unknown68; /* +0x68 */
    u8 unknown70[0x90];
    Member0079ee00 unknown100; /* +0x100 */
};

void FUN_0079ee00(Object0079ee00 *self) /* derived name */
{
    if (self->slot22()) {
        if (self->unknown100.unknown8)
            FUN_00216780(&self->unknown100);
        self->unknown68->unknownba0 = self->unknown68->unknown13c0;
        self->unknown68->unknownb90 = self->unknown68->unknown13e0;
    }
}

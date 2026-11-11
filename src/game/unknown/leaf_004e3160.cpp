/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: sets bit 9 of the flags at +0x24 of the record at +0x28
 * when the int at +0x118 equals the int at 0x57d92e0 (else clears it), then
 * calls slot 29 and passes its float on to slot 30 as a tail call; the
 * function's pointer is at 0x16aa6b8 (a vtable without a row). Class and
 * method unknown. */
struct Record004e3160 { /* derived name */
    u8 unknown0[0x24];
    u32 flags; /* +0x24 */
};

class Object004e3160 /* derived name */
{
  public:
    virtual void slot0();             /* derived name; not traced */
    virtual void slot1();             /* derived name; not traced */
    virtual void slot2();             /* derived name; not traced */
    virtual void slot3();             /* derived name; not traced */
    virtual void slot4();             /* derived name; not traced */
    virtual void slot5();             /* derived name; not traced */
    virtual void slot6();             /* derived name; not traced */
    virtual void slot7();             /* derived name; not traced */
    virtual void slot8();             /* derived name; not traced */
    virtual void slot9();             /* derived name; not traced */
    virtual void slot10();            /* derived name; not traced */
    virtual void slot11();            /* derived name; not traced */
    virtual void slot12();            /* derived name; not traced */
    virtual void slot13();            /* derived name; not traced */
    virtual void slot14();            /* derived name; not traced */
    virtual void slot15();            /* derived name; not traced */
    virtual void slot16();            /* derived name; not traced */
    virtual void slot17();            /* derived name; not traced */
    virtual void slot18();            /* derived name; not traced */
    virtual void slot19();            /* derived name; not traced */
    virtual void slot20();            /* derived name; not traced */
    virtual void slot21();            /* derived name; not traced */
    virtual void slot22();            /* derived name; not traced */
    virtual void slot23();            /* derived name; not traced */
    virtual void slot24();            /* derived name; not traced */
    virtual void slot25();            /* derived name; not traced */
    virtual void slot26();            /* derived name; not traced */
    virtual void slot27();            /* derived name; not traced */
    virtual void slot28();            /* derived name; not traced */
    virtual void slot29();            /* derived name; not traced */
    virtual void slot30(float value); /* derived name; not traced */

    u8 unknown8[0x20];
    Record004e3160 *unknown28; /* +0x28 */
    u8 unknown30[0xe8];
    int unknown118; /* +0x118 */
};

extern int D_57d92e0; /* derived name; not traced */

// NONMATCHING: greedy's spill placement: the base stores the float to its slot just before
// the first call, the build at the entry
void FUN_004e3160(Object004e3160 *self, float value) /* derived name */
{
    Record004e3160 *record = self->unknown28;
    if (self->unknown118 == D_57d92e0)
        record->flags |= 0x200;
    else
        record->flags &= ~0x200u;
    self->slot29();
    self->slot30(value);
}

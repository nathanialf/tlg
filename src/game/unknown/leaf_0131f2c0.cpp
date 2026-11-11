/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16c3b70 (+0x30 from the vtable stored at
 * 0x16c3b40) and at 0x16c3bc0 (+0x30 from the one stored at 0x16c3b90): by the
 * int at +0x34, 1 or 5 calls its argument's slot 30 and 2 its slot 28 with the
 * pointer at +0x40, a tail call; any other kind does nothing. The classes and
 * the return types are not traced. */
class Argument0131f2c0 /* derived name */
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
    virtual void slot28(void *value); /* derived name; not traced */
    virtual void slot29();            /* derived name; not traced */
    virtual void slot30(void *value); /* derived name; not traced */
};

struct Object0131f2c0 { /* derived name */
    u8 unknown0[0x34];
    int unknown34;
    u8 unknown38[0x8];
    void *unknown40;
};

// NONMATCHING: with case 2 written first the compares are the base's (1, 5, then 2), but the build lays out case 2's arm after the chain where the base lays out the 1/5 arm, and loads +0x40 in each arm where the base loads it once in the shared tail call (the call sunk with a phi of the slot, the load not): a layout and sinking residual, case 5 before case 1 in either order no better
void FUN_0131f2c0(Object0131f2c0 *self, Argument0131f2c0 *argument) /* derived name */
{
    switch (self->unknown34) {
    case 2:
        argument->slot28(self->unknown40);
        break;
    case 1:
    case 5:
        argument->slot30(self->unknown40);
        break;
    }
}

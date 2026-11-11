/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 29 of the object its second argument points to
 * with the pointer at +0x40 when the int at +0x34 is 1 or 5, as a tail call.
 * The argument's class is not traced; slot 3 of the vtables at 0x16c3b40 and
 * 0x16c3b90 (its pointers at 0x16c3b68 and 0x16c3bb8). Class and method
 * unknown. */
struct Object0131f290 { /* derived name */
    u8 unknown0[0x34];
    int unknown34;
    u8 unknown38[0x8];
    void *unknown40;
};

class Target0131f290 /* derived name */
{
  public:
    virtual void slot0();               /* derived name; not traced */
    virtual void slot1();               /* derived name; not traced */
    virtual void slot2();               /* derived name; not traced */
    virtual void slot3();               /* derived name; not traced */
    virtual void slot4();               /* derived name; not traced */
    virtual void slot5();               /* derived name; not traced */
    virtual void slot6();               /* derived name; not traced */
    virtual void slot7();               /* derived name; not traced */
    virtual void slot8();               /* derived name; not traced */
    virtual void slot9();               /* derived name; not traced */
    virtual void slot10();              /* derived name; not traced */
    virtual void slot11();              /* derived name; not traced */
    virtual void slot12();              /* derived name; not traced */
    virtual void slot13();              /* derived name; not traced */
    virtual void slot14();              /* derived name; not traced */
    virtual void slot15();              /* derived name; not traced */
    virtual void slot16();              /* derived name; not traced */
    virtual void slot17();              /* derived name; not traced */
    virtual void slot18();              /* derived name; not traced */
    virtual void slot19();              /* derived name; not traced */
    virtual void slot20();              /* derived name; not traced */
    virtual void slot21();              /* derived name; not traced */
    virtual void slot22();              /* derived name; not traced */
    virtual void slot23();              /* derived name; not traced */
    virtual void slot24();              /* derived name; not traced */
    virtual void slot25();              /* derived name; not traced */
    virtual void slot26();              /* derived name; not traced */
    virtual void slot27();              /* derived name; not traced */
    virtual void slot28();              /* derived name; not traced */
    virtual void slot29(void *pointer); /* derived name */
};

// NONMATCHING: greedy's assignment: the base gives the target's vtable rax and the pointer rdx, the compile rcx and rax; every instruction else equal (a local for the pointer compiles the same)
void FUN_0131f290(const Object0131f290 *self, Target0131f290 *target) /* derived name */
{
    if (self->unknown34 == 1 || self->unknown34 == 5) {
        target->slot29(self->unknown40);
    }
}

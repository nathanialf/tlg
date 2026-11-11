/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls slot 31 of the object its second argument points to
 * with the flag, the pointer at +0x40 and the flag again when the int at +0x48 is 5, as a
 * tail call (the sibling FUN_0131f270 calls slot 32). The argument's class is
 * not traced; slot 6 of the vtable at 0x16c3b40 (its pointer at 0x16c3b80).
 * Class and method unknown. */
struct Object0131f240 { /* derived name */
    u8 unknown0[0x40];
    void *unknown40;
    int unknown48;
};

class Target0131f240 /* derived name */
{
  public:
    virtual void slot0();                                      /* derived name; not traced */
    virtual void slot1();                                      /* derived name; not traced */
    virtual void slot2();                                      /* derived name; not traced */
    virtual void slot3();                                      /* derived name; not traced */
    virtual void slot4();                                      /* derived name; not traced */
    virtual void slot5();                                      /* derived name; not traced */
    virtual void slot6();                                      /* derived name; not traced */
    virtual void slot7();                                      /* derived name; not traced */
    virtual void slot8();                                      /* derived name; not traced */
    virtual void slot9();                                      /* derived name; not traced */
    virtual void slot10();                                     /* derived name; not traced */
    virtual void slot11();                                     /* derived name; not traced */
    virtual void slot12();                                     /* derived name; not traced */
    virtual void slot13();                                     /* derived name; not traced */
    virtual void slot14();                                     /* derived name; not traced */
    virtual void slot15();                                     /* derived name; not traced */
    virtual void slot16();                                     /* derived name; not traced */
    virtual void slot17();                                     /* derived name; not traced */
    virtual void slot18();                                     /* derived name; not traced */
    virtual void slot19();                                     /* derived name; not traced */
    virtual void slot20();                                     /* derived name; not traced */
    virtual void slot21();                                     /* derived name; not traced */
    virtual void slot22();                                     /* derived name; not traced */
    virtual void slot23();                                     /* derived name; not traced */
    virtual void slot24();                                     /* derived name; not traced */
    virtual void slot25();                                     /* derived name; not traced */
    virtual void slot26();                                     /* derived name; not traced */
    virtual void slot27();                                     /* derived name; not traced */
    virtual void slot28();                                     /* derived name; not traced */
    virtual void slot29();                                     /* derived name; not traced */
    virtual void slot30();                                     /* derived name; not traced */
    virtual void slot31(bool flag, void *pointer, bool again); /* derived name */
};

// NONMATCHING: greedy's assignment: the base gives the target's vtable rax and the pointer r9, the compile rcx and rax, with the moves ordered after them; the flag passed twice is what the base's `movzx ecx, dl; mov esi, ecx` holds (35 bytes, equal to the base's; with the flag once, 34)
void FUN_0131f240(const Object0131f240 *self, Target0131f240 *target, bool flag) /* derived name */
{
    if (self->unknown48 == 5) {
        target->slot31(flag, self->unknown40, flag);
    }
}

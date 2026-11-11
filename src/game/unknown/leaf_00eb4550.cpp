/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback FUN_00eb45d0 stores in its table (lea at
 * 0xeb471b), beside FUN_00eb4520: when the object the pointer at +0x28 of the
 * object the pointer at 0x5938c40 holds is not null, calls its slot 15 with
 * the callback's last four arguments and returns 0 when the slot returns
 * nonzero, else -0x41 (also when the object is null). The callback's first
 * two parameters are not read; their types, the member's class and the
 * arguments' types are not traced. */
class Member05938c40_28 /* derived name */
{
  public:
    virtual void slot0();                                   /* derived name; not traced */
    virtual void slot1();                                   /* derived name; not traced */
    virtual void slot2();                                   /* derived name; not traced */
    virtual void slot3();                                   /* derived name; not traced */
    virtual void slot4();                                   /* derived name; not traced */
    virtual void slot5();                                   /* derived name; not traced */
    virtual void slot6();                                   /* derived name; not traced */
    virtual void slot7();                                   /* derived name; not traced */
    virtual void slot8();                                   /* derived name; not traced */
    virtual void slot9();                                   /* derived name; not traced */
    virtual void slot10();                                  /* derived name; not traced */
    virtual void slot11();                                  /* derived name; not traced */
    virtual void slot12();                                  /* derived name; not traced */
    virtual void slot13();                                  /* derived name; not traced */
    virtual void slot14();                                  /* derived name; not traced */
    virtual int slot15(void *a, void *b, void *c, void *d); /* derived name; not traced */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x28];
    Member05938c40_28 *unknown28;
};

extern Object05938c40 *D_5938c40;

// NONMATCHING: list-ilp order: the build places `mov eax, -0x41` before the test of the slot's result, so the result is first copied to ecx; the base tests eax, then loads the constant (xor ecx, ecx; test eax, eax; mov eax, -0x41; cmovne); written as one `if` with && the null path is no longer shared
int FUN_00eb4550(void *, void *, void *a, void *b, void *c, void *d) /* derived name */
{
    Member05938c40_28 *member = D_5938c40->unknown28;
    if (!member)
        return -0x41;
    return member->slot15(a, b, c, d) ? 0 : -0x41;
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 3 of the vtable at 0x16c2050 (its pointer at 0x16c2078; stored
 * by FUN_011f8030): passes the object to slot 5 of the listener in each
 * 24-byte entry of the array at +0x290 of its owner (the pointer at +0x8),
 * the count at +0x298 read again after each call. The types and the slots'
 * meaning are not traced. */
struct Object01212400; /* derived name */

class Listener01212400 /* derived name */
{
  public:
    virtual void slot0();                       /* derived name; not traced */
    virtual void slot1();                       /* derived name; not traced */
    virtual void slot2();                       /* derived name; not traced */
    virtual void slot3();                       /* derived name; not traced */
    virtual void slot4();                       /* derived name; not traced */
    virtual void slot5(Object01212400 *object); /* derived name */
};

struct Entry01212400 { /* derived name */
    u8 unknown0[0x8];
    Listener01212400 *unknown8; /* +0x8 */
    u8 unknown10[0x8];
};

struct Owner01212400 { /* derived name */
    u8 unknown0[0x290];
    Entry01212400 *unknown290; /* +0x290 */
    u32 unknown298;            /* +0x298: the count of +0x290 */
};

struct Object01212400 {      /* derived name */
    void *unknown0;          /* +0x0: the vtable */
    Owner01212400 *unknown8; /* +0x8 */
};

// NONMATCHING: the index: the base keeps the int counter 32 bits and
// sign-extends it for each entry (`movsxd rbx, ebx`); this build widens it and
// strength-reduces the entry's address (IndVarSimplify, round 164C's 0xf501a0).
void FUN_01212400(Object01212400 *self) /* derived name */
{
    for (int i = 0; i < self->unknown8->unknown298; i++)
        self->unknown8->unknown290[i].unknown8->slot5(self);
}

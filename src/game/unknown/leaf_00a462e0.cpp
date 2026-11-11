/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived names: a script C function: gives the truth of its first argument
 * (nil and false are false, a missing argument nil) to slot 17 of the object
 * at +0x100 of the object the pointer at 0x5938c40 holds; returns no values.
 * The slot's meaning and the function's name are not traced. */
class Member05938c40_100 /* derived name */
{
  public:
    virtual void slot0();         /* derived name; not traced */
    virtual void slot1();         /* derived name; not traced */
    virtual void slot2();         /* derived name; not traced */
    virtual void slot3();         /* derived name; not traced */
    virtual void slot4();         /* derived name; not traced */
    virtual void slot5();         /* derived name; not traced */
    virtual void slot6();         /* derived name; not traced */
    virtual void slot7();         /* derived name; not traced */
    virtual void slot8();         /* derived name; not traced */
    virtual void slot9();         /* derived name; not traced */
    virtual void slot10();        /* derived name; not traced */
    virtual void slot11();        /* derived name; not traced */
    virtual void slot12();        /* derived name; not traced */
    virtual void slot13();        /* derived name; not traced */
    virtual void slot14();        /* derived name; not traced */
    virtual void slot15();        /* derived name; not traced */
    virtual void slot16();        /* derived name; not traced */
    virtual void slot17(bool on); /* derived name */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x100];
    Member05938c40_100 *unknown100; /* +0x100 */
};

extern Object05938c40 *D_5938c40;

// NONMATCHING: greedy's assignment, FUN_00a44f20's: the argument pointer and the zero of the
// select swapped (rcx/rax against the base's rax/rcx), the rest the same shape
int FUN_00a462e0(lua_State *state) /* derived name */
{
    const HksObject *value = state->base < state->top ? state->base : 0;
    int type = state->base < state->top ? value->type & 0xf : 0;
    bool on = false;
    if (type != 0) {
        on = true;
        if (type == 1)
            on = value->value.boolean != 0;
    }
    D_5938c40->unknown100->slot17(on);
    return 0;
}

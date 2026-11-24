/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived names: a script C function (no direct caller): the truths of its
 * first two arguments and of its third when there are three (false
 * otherwise) passed to slot 13 of the sound object at +0x100 of the object
 * the pointer at 0x5938c40 holds; returns 0 (no results). */
class Sound05938c40_100 /* derived name */
{
  public:
    virtual void slot0();                        /* derived name; not traced */
    virtual void slot1();                        /* derived name; not traced */
    virtual void slot2();                        /* derived name; not traced */
    virtual void slot3();                        /* derived name; not traced */
    virtual void slot4();                        /* derived name; not traced */
    virtual void slot5();                        /* derived name; not traced */
    virtual void slot6();                        /* derived name; not traced */
    virtual void slot7();                        /* derived name; not traced */
    virtual void slot8();                        /* derived name; not traced */
    virtual void setPause(bool paused);          /* slot 9, derived name */
    virtual void setPauseSystem(bool paused);    /* slot 10, derived name */
    virtual void slot11();                       /* derived name; not traced */
    virtual void slot12();                       /* derived name; not traced */
    virtual void slot13(bool a, bool b, bool c); /* derived name */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x100];
    Sound05938c40_100 *unknown100; /* +0x100 */
};

extern Object05938c40 *D_5938c40;

// NONMATCHING: register assignment (199 bytes against 194): with toBoolean's select kept the three
// truths' blocks are the base's (`mov r9b, 1` before `cmp esi, 1`); the base keeps the frame's top
// in r8, the first slot in rax and the zeros in r9 and rcx, the build in rdx, rcx, rsi and rax, and
// it makes the third truth's false in a block of its own after the call (`xor r9d, r9d; jmp`)
int FUN_00a46210(lua_State *state) /* derived name */
{
    bool a = toBoolean(state, 1);
    bool b = toBoolean(state, 2);
    bool c = argumentCount(state) >= 3 ? toBoolean(state, 3) : false;
    D_5938c40->unknown100->slot13(a, b, c);
    return 0;
}

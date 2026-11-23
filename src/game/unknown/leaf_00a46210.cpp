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

/* derived name: an argument's truth, false past the frame's top (as
 * FUN_00e7d050's unit has it: the argument by reference, known not null) */
static inline bool argumentTruth(const HksObject &argument, const HksObject *top)
{
    const HksObject *value = &argument < top ? &argument : 0;
    if (value) {
        int type = value->type & 0xf;
        if (type == 0)
            return false;
        if (type == 1)
            return value->value.boolean != 0;
        return true;
    }
    return false;
}

// NONMATCHING: the truths' blocks, the residual of FUN_00e7cff0 and
// FUN_00e7d050 three times over: the base sets `true` before `cmp esi, 1`
// (the nil test a `je` to a block that clears it), the build places the copy
// of `true` in a block of its own on the split edge; 11 bytes longer.
int FUN_00a46210(lua_State *state) /* derived name */
{
    bool a = argumentTruth(state->base[0], state->top);
    bool b = argumentTruth(state->base[1], state->top);
    bool c = argumentCount(state) >= 3 ? argumentTruth(state->base[2], state->top) : false;
    D_5938c40->unknown100->slot13(a, b, c);
    return 0;
}

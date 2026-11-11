/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived names: the script C function "SoundSetPause" (FUN_00e7d5a0
 * registers it through FUN_00dd6ba0, lea at 0xe7d778): with at least one
 * argument, takes its truth (false for nil, a boolean's value, true for any
 * other type; false when the frame is empty) and passes it to slot 9 of the
 * object the pointer at +0x100 of the object the pointer at 0x5938c40 holds;
 * returns 0 (no results). The C function's own name is unknown. */
class Sound05938c40_100 /* derived name */
{
  public:
    virtual void slot0();                     /* derived name; not traced */
    virtual void slot1();                     /* derived name; not traced */
    virtual void slot2();                     /* derived name; not traced */
    virtual void slot3();                     /* derived name; not traced */
    virtual void slot4();                     /* derived name; not traced */
    virtual void slot5();                     /* derived name; not traced */
    virtual void slot6();                     /* derived name; not traced */
    virtual void slot7();                     /* derived name; not traced */
    virtual void slot8();                     /* derived name; not traced */
    virtual void setPause(bool paused);       /* slot 9, derived name */
    virtual void setPauseSystem(bool paused); /* slot 10, derived name */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x100];
    Sound05938c40_100 *unknown100; /* +0x100 */
};

extern Object05938c40 *D_5938c40;

/* derived name: the truth of the frame's first argument, false when the
 * frame is empty. The argument comes by reference, so it is known not null
 * and the null test of the selected value folds into the frame test before
 * the helper is inlined (the base's `cmp base, top; cmovae; jae`, the select
 * kept for the loads) */
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

// NONMATCHING: the PHI copy of `true` is placed in a block of its own on the
// split edge (`mov cl, 1; jmp`) where the base sets it before `cmp edx, 1`
// with the type in edx (the build keeps the type in ecx); 2 bytes longer
int FUN_00e7cff0(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count > 0) {
        bool paused = argumentTruth(*state->base, state->top);
        D_5938c40->unknown100->setPause(paused);
    }
    return 0;
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_hks.h"

/* derived names: the script C function "SoundSetPauseSystem" (FUN_00e7d5a0
 * registers it through FUN_00dd6ba0, lea at 0xe7d807): with at least one
 * argument, takes its truth (false for nil, a boolean's value, true for any
 * other type; false when the frame is empty) and passes it to slot 10 of the
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

// NONMATCHING: the base folds the null test of the selected argument into the frame test (`cmp base, top; cmovae; jae`, the select kept) where the build tests base for null first; 12 of 33
int FUN_00e7d050(lua_State *state) /* derived name */
{
    int count = state->top - state->base;
    if (count > 0) {
        const HksObject *value = state->base < state->top ? state->base : 0;
        bool truth = false;
        if (value) {
            int type = value->type & 0xf;
            if (type == 0)
                truth = false;
            else if (type == 1)
                truth = value->value.boolean != 0;
            else
                truth = true;
        }
        D_5938c40->unknown100->setPauseSystem(truth);
    }
    return 0;
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: a script C function FUN_00e7d5a0 registers through
 * FUN_00dd6ba0 under the name "SoundToolReleaseResource" (lea at 0xe7dd0e):
 * unless the count of its arguments (the stack top less the frame's base, in
 * 16-byte values) is negative, calls slot 29 of the object at +0x100 of the
 * object the pointer at 0x5938c40 holds; returns 0 (no results). The C
 * function's own name is unknown; the member's class and the slot's return
 * type are not traced. */
class Member05938c40_100 /* derived name */
{
  public:
    virtual void slot0();  /* derived name; not traced */
    virtual void slot1();  /* derived name; not traced */
    virtual void slot2();  /* derived name; not traced */
    virtual void slot3();  /* derived name; not traced */
    virtual void slot4();  /* derived name; not traced */
    virtual void slot5();  /* derived name; not traced */
    virtual void slot6();  /* derived name; not traced */
    virtual void slot7();  /* derived name; not traced */
    virtual void slot8();  /* derived name; not traced */
    virtual void slot9();  /* derived name; not traced */
    virtual void slot10(); /* derived name; not traced */
    virtual void slot11(); /* derived name; not traced */
    virtual void slot12(); /* derived name; not traced */
    virtual void slot13(); /* derived name; not traced */
    virtual void slot14(); /* derived name; not traced */
    virtual void slot15(); /* derived name; not traced */
    virtual void slot16(); /* derived name; not traced */
    virtual void slot17(); /* derived name; not traced */
    virtual void slot18(); /* derived name; not traced */
    virtual void slot19(); /* derived name; not traced */
    virtual void slot20(); /* derived name; not traced */
    virtual void slot21(); /* derived name; not traced */
    virtual void slot22(); /* derived name; not traced */
    virtual void slot23(); /* derived name; not traced */
    virtual void slot24(); /* derived name; not traced */
    virtual void slot25(); /* derived name; not traced */
    virtual void slot26(); /* derived name; not traced */
    virtual void slot27(); /* derived name; not traced */
    virtual void slot28(); /* derived name; not traced */
    virtual void slot29(); /* derived name; not traced */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x100];
    Member05938c40_100 *unknown100;
};

extern Object05938c40 *D_5938c40;

int FUN_00e7d500(lua_State *state) /* derived name */
{
    if (static_cast<int>(state->top - state->base) >= 0)
        D_5938c40->unknown100->slot29();
    return 0;
}

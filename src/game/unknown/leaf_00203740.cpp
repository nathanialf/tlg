/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a script C function that calls slot 9 of the object at +0x30
 * of the object the pointer at 0x5938c40 holds and returns 0 (no results).
 * FUN_001bd010 registers it (lea at 0x1db831) through FUN_00c87e30 under the
 * script name "PrintFps" (its description "PrintFps() Print fps, cputime,
 * gputime."); the VM's strings name lua_State. The C function's own name is
 * unknown. The member's class and the slot's return type are not traced. */
struct lua_State;

class Member05938c40_30 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual void slot7(); /* derived name; not traced */
    virtual void slot8(); /* derived name; not traced */
    virtual void slot9(); /* derived name; not traced */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x30];
    Member05938c40_30 *unknown30;
};

extern Object05938c40 *D_5938c40;

int FUN_00203740(lua_State *state) /* derived name */
{
    D_5938c40->unknown30->slot9();
    return 0;
}

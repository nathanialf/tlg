/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a script C function that calls slot 12 of the object at +0xd0
 * of the object the pointer at 0x57c9390 holds and returns 0 (no results).
 * FUN_008817d0 registers it (lea at 0x88184f) through FUN_00c87e30 under the
 * script name "GameMenu_NotifyEnd"; the VM's strings name lua_State. The C
 * function's own name is unknown. The member's class and the slot's return
 * type are not traced. */
struct lua_State;

class Member057c9390_d0 /* derived name */
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
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0xd0];
    Member057c9390_d0 *unknownd0;
};

extern Object057c9390 *D_57c9390;

int FUN_00881670(lua_State *state) /* derived name */
{
    D_57c9390->unknownd0->slot12();
    return 0;
}

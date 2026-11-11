/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: the script C function "GameMenu_IsEnd" (FUN_008817d0
 * registers it through FUN_00c87e30, lea at 0x88186f): pushes the result of
 * slot 13 of the object the pointer at +0xd0 of the object the pointer at
 * 0x57c9390 holds, as a boolean, and returns one result. The menu's class is
 * not traced. The C function's own name is unknown. */
class Menu057c9390_d0 /* derived name */
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
    virtual bool slot13(); /* derived name; whether the menu has ended */
};

struct Object057c9390 /* derived name */
{
    u8 unknown0[0xd0];
    Menu057c9390_d0 *unknownD0; /* +0xd0 */
};

extern Object057c9390 *D_57c9390;

int FUN_00881690(lua_State *state) /* derived name */
{
    bool ended = D_57c9390->unknownD0->slot13();
    HksObject *top = state->top;
    top->value.boolean = ended;
    top->type = 1;
    state->top = top + 1;
    return 1;
}

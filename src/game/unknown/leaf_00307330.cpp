/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 14 of the vtable at 0x16a8430 (no row; the method stores no
 * vptr). When bit 0 of the byte at +0x44c is set, the int at +0x30 is 0 or
 * the int at +0x90 is not, the int at +0x40 of the controller's state is
 * cleared; otherwise the controller's int at +0x6c becomes 1 when the
 * state's ints at +0x30 or +0x40 are 0, the state's +0x40 becomes 1, and the
 * controller's slots 9 and 6 are called with this object. The classes are
 * not traced. */
struct State00307330 { /* derived name */
    u8 unknown0[0x30];
    int unknown30;
    u8 unknown34[0xc];
    int unknown40;
};

struct Object00307330;

class Controller00307330 /* derived name */
{
  public:
    virtual void slot0();                       /* derived name; not traced */
    virtual void slot1();                       /* derived name; not traced */
    virtual void slot2();                       /* derived name; not traced */
    virtual void slot3();                       /* derived name; not traced */
    virtual void slot4();                       /* derived name; not traced */
    virtual void slot5();                       /* derived name; not traced */
    virtual void slot6(Object00307330 *object); /* derived name */
    virtual void slot7();                       /* derived name; not traced */
    virtual void slot8();                       /* derived name; not traced */
    virtual void slot9(Object00307330 *object); /* derived name */

    u8 unknown8[0x20];
    State00307330 *state; /* +0x28 */
    u8 unknown30[0x3c];
    int unknown6c;
};

struct Object00307330 { /* derived name */
    u8 unknown0[0x30];
    int unknown30;
    u8 unknown34[0x5c];
    int unknown90;
    u8 unknown94[0x310 - 0x94];
    Controller00307330 *controller; /* +0x310 */
    u8 unknown318[0x44c - 0x318];
    u8 flags44c; /* bit 0 tested */
};

// The base materialises the state's +0x40 in the join (add rax, 0x40): GVN's
// scalar PRE stops after its last change (docs/DECISIONS.md D64).
void FUN_00307330(Object00307330 *self) /* derived name */
{
    if ((self->flags44c & 1) || self->unknown30 == 0 || self->unknown90 != 0) {
        self->controller->state->unknown40 = 0;
        return;
    }
    Controller00307330 *controller = self->controller;
    State00307330 *state = controller->state;
    if (state->unknown30 == 0 || state->unknown40 == 0)
        controller->unknown6c = 1;
    state->unknown40 = 1;
    self->controller->slot9(self);
    self->controller->slot6(self);
}

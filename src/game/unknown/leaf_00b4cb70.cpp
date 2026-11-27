/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: a function of a class derived from the scene node (its
 * address in a vtable at 0x16b6648): bit 0 of the byte at +0x580
 * is cleared, then the node's first component of the type the pointer at
 * 0x5946a58 holds, found under the node's reader count, has its int at +0x5c
 * set to 0x80000000 where it is not, with bit 2 of its flags (+0x20) set. The
 * class and the component's are not traced. */
extern const Type00503fb0 *D_5946a58; /* derived name */

class Node00b4cb70 : public Object016b85e0 /* derived name */
{
  public:
    u8 unknown238[0x348];
    unsigned
        flags580; /* +0x580: bit 0 set by FUN_00b4ca50, cleared here (a word: 0xb4ca5c reads it whole) */
};

struct Value00b4cb70 { /* derived name: the component's int at +0x5c */
    u8 unknown0[0x5c];
    int value; /* +0x5c */
};

void FUN_00b4cb70(Node00b4cb70 *self) /* derived name */
{
    self->flags580 &= ~1;
    if (Component00503fb0 *component = self->component(D_5946a58)) {
        Value00b4cb70 *view = reinterpret_cast<Value00b4cb70 *>(component);
        if (view->value != int(0x80000000)) {
            view->value = 0x80000000;
            component->flags |= 4;
        }
    }
}

/* derived names: the same class's switch of bit 0 of +0x580: set, the
 * component's int at +0x5c is cleared where it is not 0 (bit 2 of its flags
 * set with it); cleared, FUN_00b4cb70 (inlined: the flags' word read once
 * before the test, `mov eax, [r14+0x580]`) */
void FUN_00b4ca50(Node00b4cb70 *self, int on) /* derived name */
{
    if (on) {
        self->flags580 |= 1;
        if (Component00503fb0 *component = self->component(D_5946a58)) {
            Value00b4cb70 *view = reinterpret_cast<Value00b4cb70 *>(component);
            if (view->value != 0) {
                view->value = 0;
                component->flags |= 4;
            }
        }
    } else {
        FUN_00b4cb70(self);
    }
}

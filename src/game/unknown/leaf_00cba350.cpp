/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: called by FUN_00cb8ac0 and by itself: the node the pointer at
 * +0x0 holds first, then slot 6 of the object at +0x18, when present, with
 * the same two arguments (a tail call). The argument and member types are not
 * traced. */
class Handler00cba350 /* derived name */
{
  public:
    virtual void slot0();                          /* derived name; not traced */
    virtual void slot1();                          /* derived name; not traced */
    virtual void slot2();                          /* derived name; not traced */
    virtual void slot3();                          /* derived name; not traced */
    virtual void slot4();                          /* derived name; not traced */
    virtual void slot5();                          /* derived name; not traced */
    virtual void slot6(void *first, void *second); /* derived name; not traced */
};

struct Node00cba350 { /* derived name */
    Node00cba350 *unknown0;
    u8 unknown8[0x10];
    Handler00cba350 *unknown18;
};

void FUN_00cba350(Node00cba350 *self, void *first, void *second) /* derived name */
{
    if (self->unknown0)
        FUN_00cba350(self->unknown0, first, second);
    if (self->unknown18)
        self->unknown18->slot6(first, second);
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: when the int at +0x20 is nonzero, marks the int at +0x7dfc
 * set the first time and, when it is already set, reports "Duplicate
 * 'proxytable' slot definition." through slot 3 of the object the pointer at
 * +0x18 holds, a tail call; slot 141 of the vtable at 0x16bb0c0 (its pointer
 * at 0x16bb538), stored by FUN_00da4250 and FUN_00ddbb60. The reporter's class
 * and the return type are not traced. */
class Reporter00db2870 /* derived name */
{
  public:
    virtual void slot0();                    /* derived name; not traced */
    virtual void slot1();                    /* derived name; not traced */
    virtual void slot2();                    /* derived name; not traced */
    virtual void slot3(const char *message); /* derived name; not traced */
};

struct Object00db2870 { /* derived name */
    u8 unknown0[0x18];
    Reporter00db2870 *unknown18;
    int unknown20;
    u8 unknown24[0x7dd8];
    int unknown7dfc;
};

void FUN_00db2870(Object00db2870 *self) /* derived name */
{
    if (self->unknown20 == 0)
        return;
    if (self->unknown7dfc)
        self->unknown18->slot3("Duplicate 'proxytable' slot definition.");
    else
        self->unknown7dfc = 1;
}

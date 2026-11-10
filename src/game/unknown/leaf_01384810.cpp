/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns by value (through the hidden pointer) what its own
 * slot 6 returns; slot 7 of the vtable at 0x16b1808 (its pointer at
 * 0x16b1840), and two more pointers. The value's type is not traced (a record
 * returned in memory). Class and method unknown. */
struct Value01384810 { /* derived name */
    void *unknown0;
    void *unknown8;
    void *unknown10;
};

class Object01384810 /* derived name */
{
  public:
    virtual void slot0();          /* derived name; not traced */
    virtual void slot1();          /* derived name; not traced */
    virtual void slot2();          /* derived name; not traced */
    virtual void slot3();          /* derived name; not traced */
    virtual void slot4();          /* derived name; not traced */
    virtual void slot5();          /* derived name; not traced */
    virtual Value01384810 slot6(); /* derived name; not traced */
};

Value01384810 FUN_01384810(Object01384810 *self) /* derived name */
{
    return self->slot6();
}

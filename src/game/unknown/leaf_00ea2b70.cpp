/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 39 of the vtable at 0x16be490: when the record at +0x268
 * is set, slot 5 of the object at +0x1e0 of its record at +0x38, with the
 * pointer at +0x20 of that record and 0, as a tail call. The types are not
 * traced. Class and method unknown. */
class Target00ea2b70 /* derived name */
{
  public:
    virtual void slot0();                       /* derived name; not traced */
    virtual void slot1();                       /* derived name; not traced */
    virtual void slot2();                       /* derived name; not traced */
    virtual void slot3();                       /* derived name; not traced */
    virtual void slot4();                       /* derived name; not traced */
    virtual void slot5(void *value, int flags); /* derived name; not traced */
};

struct Inner00ea2b70 { /* derived name */
    u8 unknown0[0x20];
    void *unknown20;
    u8 unknown28[0x1b8];
    Target00ea2b70 *unknown1e0;
};

struct Record00ea2b70 { /* derived name */
    u8 unknown0[0x38];
    Inner00ea2b70 *unknown38;
};

struct Object00ea2b70 { /* derived name */
    u8 unknown0[0x268];
    Record00ea2b70 *unknown268;
};

void FUN_00ea2b70(Object00ea2b70 *self) /* derived name */
{
    if (Record00ea2b70 *record = self->unknown268) {
        Inner00ea2b70 *inner = record->unknown38;
        inner->unknown1e0->slot5(inner->unknown20, 0);
    }
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 70 of the vtable at 0x16bb0c0 (the vtable of
 * FUN_00daf400's object): FUN_00db1aa0 on the object with 0x12020000 and the
 * int slot 6 of the object at +0x18 returns, as a tail call. The types are not
 * traced. Class and method unknown. */
class Source00daccc0 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual int slot6();  /* derived name; not traced */
};

struct Object00daccc0 { /* derived name */
    u8 unknown0[0x18];
    Source00daccc0 *unknown18;
};

void FUN_00db1aa0(Object00daccc0 *self, u32 code, int value); /* derived name */

void FUN_00daccc0(Object00daccc0 *self) /* derived name */
{
    FUN_00db1aa0(self, 0x12020000, self->unknown18->slot6());
}

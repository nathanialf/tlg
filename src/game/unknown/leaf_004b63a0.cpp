/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_simd.h"

/* derived names: slot 9 of the vtable at 0x16aa290 (its pointer at 0x16aa2e8;
 * stored by FUN_004b60b0 and FUN_004b6250, no row), written as a free
 * function: copies the vector at +0x40 to +0x60, calls the object's own slot
 * 11 with the vectors at +0x40 and +0x50, then stores in the flag at +0x3c
 * whether the check FUN_004b63e0 fails when asked for (true when not asked).
 * The vectors' meaning and the check are not traced. */
class Object004b63a0 /* derived name */
{
  public:
    virtual void slot0();                              /* derived name; not traced */
    virtual void slot1();                              /* derived name; not traced */
    virtual void slot2();                              /* derived name; not traced */
    virtual void slot3();                              /* derived name; not traced */
    virtual void slot4();                              /* derived name; not traced */
    virtual void slot5();                              /* derived name; not traced */
    virtual void slot6();                              /* derived name; not traced */
    virtual void slot7();                              /* derived name; not traced */
    virtual void slot8();                              /* derived name; not traced */
    virtual void slot9();                              /* derived name; not traced */
    virtual void slot10();                             /* derived name; not traced */
    virtual void slot11(const Vec4 *a, const Vec4 *b); /* derived name; not traced */

    u8 unknown8[0x34];
    bool unknown3c; /* +0x3c */
    u8 unknown3d[3];
    Vec4 unknown40; /* +0x40 */
    Vec4 unknown50; /* +0x50 */
    Vec4 unknown60; /* +0x60 */
};

bool FUN_004b63e0(Object004b63a0 *self); /* derived name */

void FUN_004b63a0(Object004b63a0 *self, int check) /* derived name */
{
    self->unknown60 = self->unknown40;
    self->slot11(&self->unknown40, &self->unknown50);
    self->unknown3c = !check || !FUN_004b63e0(self);
}

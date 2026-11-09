/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns its own slot 10's int result, called through the
 * vtable as a tail call, when the int at +0x50 is zero, and 1 otherwise; slot
 * 9 of the vtable at 0x16b0788 (its pointer at 0x16b07e0), the vtable stored
 * by FUN_008ef2f0 FUN_008ef5c0; slot 9 of the vtable at 0x16b0808 (its pointer
 * at 0x16b0860), the vtable stored by FUN_008ef5c0; slot 9 of the vtable at
 * 0x16b54b8 (its pointer at 0x16b5510), the vtable stored by FUN_008ef2f0
 * FUN_008ef5c0 FUN_008f2ec0 FUN_008f2f20 FUN_00b20380 FUN_00b20610
 * FUN_00b20670. Class and method unknown. */
class Object00b206d0 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual void slot7(); /* derived name; not traced */
    virtual void slot8(); /* derived name; not traced */
    virtual void slot9(); /* derived name; not traced */
    virtual int slot10(); /* derived name; not traced */

    u8 unknown8[0x50 - 8];
    int unknown50;
};

int FUN_00b206d0(Object00b206d0 *self) /* derived name */
{
    if (!self->unknown50) {
        return self->slot10();
    }
    return 1;
}

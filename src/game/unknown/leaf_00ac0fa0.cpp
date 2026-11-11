/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16b35c0 (+0x20 from the vtable stored at
 * 0x16b35a0): when FUN_004593b0 returns more than 2 for the pointer at +0x0 of
 * the record at +0x8, returns the record's pointer at +0x20, else what
 * FUN_00abf840 returns for the record. The types are not traced. */
struct Record00ac0fa0 { /* derived name */
    void *unknown0;
    u8 unknown8[0x18];
    void *unknown20;
};

class Object00ac0fa0 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */

    Record00ac0fa0 *unknown8;
};

int FUN_004593b0(void *value);              /* derived name */
void *FUN_00abf840(Record00ac0fa0 *record); /* derived name */

void *FUN_00ac0fa0(Object00ac0fa0 *self) /* derived name */
{
    if (FUN_004593b0(self->unknown8->unknown0) > 2) {
        return self->unknown8->unknown20;
    }
    return FUN_00abf840(self->unknown8);
}

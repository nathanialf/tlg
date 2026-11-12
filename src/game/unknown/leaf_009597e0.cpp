/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: with a record at +0x178, asks each of the checks at +0x180
 * (the count at +0x188) through its slot 0 and returns 0 at the first that
 * answers 0; otherwise sets the int at +0x48 to the record's int at +0x4c
 * plus 12 (bit 6 of the flags at +0x1f4 set), 6 (the record's int at +0x50
 * is 1) or 9, calls FUN_009697f0 on the record and FUN_00d243e0 on itself
 * and returns 1; 1 without a record. */
class Check009597e0 /* derived name */
{
  public:
    virtual int slot0(); /* derived name; not traced */
};

struct Record009597e0 { /* derived name */
    u8 unknown0[0x4c];
    int unknown4c; /* +0x4c */
    int unknown50; /* +0x50 */
};

struct Object009597e0 { /* derived name */
    u8 unknown0[0x48];
    int unknown48; /* +0x48 */
    u8 unknown4c[0x12c];
    Record009597e0 *unknown178; /* +0x178 */
    Check009597e0 **checks;     /* +0x180 */
    u32 checkCount;             /* +0x188 */
    u8 unknown18c[0x68];
    u32 flags1f4; /* +0x1f4 */
};

void FUN_009697f0(Record009597e0 *record); /* derived name */
void FUN_00d243e0(Object009597e0 *self);   /* derived name */

// NONMATCHING: the base keeps the check index int, sign-extended at each use (the parked
// IndVarSimplify class), and the record in rsi
int FUN_009597e0(Object009597e0 *self) /* derived name */
{
    if (!self->unknown178)
        return 1;
    for (int i = 0; i < self->checkCount; i++) {
        if (!self->checks[i]->slot0())
            return 0;
    }
    Record009597e0 *record = self->unknown178;
    int step = 9;
    if (self->flags1f4 & 0x40)
        step = 12;
    else if (record->unknown50 == 1)
        step = 6;
    self->unknown48 = step + record->unknown4c;
    FUN_009697f0(record);
    FUN_00d243e0(self);
    return 1;
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 11 of the vtable at 0x16ac108 (its pointer at
 * 0x16ac170), stored by FUN_00670560: looks the 64-bit value at 0x581b938 up
 * through FUN_00c57870 in the object the pointer at +0x38 holds (when there is
 * one), with 0, and passes bit 0 of the int at +0x250 of the record it
 * returns (0 when there is no object or no record) to FUN_00822740 with the
 * object, a tail call. The value's and the records' types and the callees'
 * results are not traced. Class and method unknown. */
struct Record00c57870 /* derived name */
{
    u8 unknown0[0x250];
    int unknown250; /* +0x250 */
};

struct Owner00c57870; /* derived name */

struct Object00670990 /* derived name */
{
    u8 unknown0[0x38];
    Owner00c57870 *unknown38; /* +0x38 */
};

extern u64 D_581b938;

Record00c57870 *FUN_00c57870(Owner00c57870 *owner, u64 key, int unknown2); /* derived name */
void FUN_00822740(Object00670990 *self, int flag);                         /* derived name */

// NONMATCHING: the default's placement (D48's edge splitting the candidate): this
// sets the 0 before the first test in a callee-saved register kept across the
// call, where the base sets it in one block both null tests reach (`xor esi, esi`
// before the tail call); a ternary spelling gives the same.
void FUN_00670990(Object00670990 *self) /* derived name */
{
    int flag = 0;
    if (self->unknown38) {
        Record00c57870 *record = FUN_00c57870(self->unknown38, D_581b938, 0);
        if (record)
            flag = record->unknown250 & 1;
    }
    FUN_00822740(self, flag);
}

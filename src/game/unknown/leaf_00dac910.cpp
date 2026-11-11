/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 87 of the vtable at 0x16bb0c0 (its pointer at
 * 0x16bb388; the family of FUN_00da5be0, home BytecodeReader.cpp): calls
 * FUN_00daa450 with the object and the pointer at +0x16f0 of the record at
 * +0x7dc8, then, keeping that record's pointer at +0x1d50, FUN_013bdfe0 with
 * the address of its field at +0x17c0, then FUN_013be1a0 with the pointer
 * kept, a tail call. The types beyond their widths are not traced. */
struct Record00dac910 { /* derived name */
    u8 unknown0[0x16f0];
    void *unknown16f0; /* +0x16f0 */
    u8 unknown16f8[0xc8];
    u8 unknown17c0; /* type not traced; its address is passed */
    u8 unknown17c1[0x58f];
    void *unknown1d50; /* +0x1d50 */
};

struct Object00dac910 { /* derived name */
    u8 unknown0[0x7dc8];
    Record00dac910 *unknown7dc8;
};

void FUN_00daa450(Object00dac910 *self, void *value); /* derived name */
void FUN_013bdfe0(void *field);                       /* derived name */
void FUN_013be1a0(void *value);                       /* derived name */

void FUN_00dac910(Object00dac910 *self) /* derived name */
{
    FUN_00daa450(self, self->unknown7dc8->unknown16f0);
    void *kept = self->unknown7dc8->unknown1d50;
    FUN_013bdfe0(&self->unknown7dc8->unknown17c0);
    FUN_013be1a0(kept);
}

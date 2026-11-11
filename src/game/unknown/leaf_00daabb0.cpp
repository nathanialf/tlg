/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 119 of the vtable at 0x16bb0c0 (its pointer at
 * 0x16bb488; the family of FUN_00da5be0, slot 132, home BytecodeReader.cpp):
 * keeps the pointer at +0x16f0 of the record at +0x7dc8, calls FUN_013bdca0
 * with the address of that record's field at +0x1340 (as FUN_00da5be0), then
 * FUN_00da88a0 with the object, the pointer at +0x16f0 read again and the
 * one kept, a tail call. The types beyond their widths are not traced. */
struct Record00daabb0 { /* derived name */
    u8 unknown0[0x1340];
    u8 unknown1340; /* type not traced; its address is passed */
    u8 unknown1341[0x3af];
    void *unknown16f0; /* +0x16f0 */
};

struct Object00daabb0 { /* derived name */
    u8 unknown0[0x7dc8];
    Record00daabb0 *unknown7dc8;
};

void FUN_013bdca0(void *field);                                         /* derived name */
void FUN_00da88a0(Object00daabb0 *self, void *current, void *previous); /* derived name */

void FUN_00daabb0(Object00daabb0 *self) /* derived name */
{
    void *previous = self->unknown7dc8->unknown16f0;
    FUN_013bdca0(&self->unknown7dc8->unknown1340);
    FUN_00da88a0(self, self->unknown7dc8->unknown16f0, previous);
}

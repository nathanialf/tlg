/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_hks.h"

/* derived names: slot 85 of the vtable at 0x16bb0c0 (its pointer at
 * 0x16bb378; the family of FUN_00da8f40, slot 102): hands its pointer argument as
 * a value of type 4 to FUN_00da9130 (which reads the type and copies the
 * 16 bytes), then resets the record the pointer at +0x16f0 of the record at
 * +0x7dc8 points to (read before the call) as FUN_00da8f40 does, with the
 * kind 4 at +0x0 and +0x60 and the callee's result at +0x8. Class and method
 * unknown; the fields' types beyond their widths are not traced. */
struct Target00dac0e0 { /* derived name */
    int unknown0;       /* +0x0: the kind */
    u8 unknown4[4];
    int unknown8; /* +0x8 */
    u8 unknownc[0x2c];
    int unknown38; /* +0x38 */
    int unknown3c; /* +0x3c */
    char unknown40[0x10];
    char *unknown50; /* +0x50 */
    char *unknown58; /* +0x58 */
    int unknown60;   /* +0x60 */
    u8 unknown64[4];
    void *unknown68; /* +0x68 */
};

struct Record00dac0e0 { /* derived name */
    u8 unknown0[0x16f0];
    Target00dac0e0 *unknown16f0;
};

struct Object00dac0e0 { /* derived name */
    u8 unknown0[0x7dc8];
    Record00dac0e0 *unknown7dc8;
};

int FUN_00da9130(Object00dac0e0 *self, const HksObject *value); /* derived name */

// NONMATCHING: register exchange: the base holds the buffer's address in rcx and the byte before it in rdx, the build the other way
void FUN_00dac0e0(Object00dac0e0 *self, void *pointer) /* derived name */
{
    Target00dac0e0 *target = self->unknown7dc8->unknown16f0;
    HksObject value;
    value.value.pointer = pointer;
    value.type = 4;
    int result = FUN_00da9130(self, &value);
    target->unknown0 = 4;
    target->unknown38 = -1;
    target->unknown3c = -1;
    target->unknown50 = target->unknown40;
    target->unknown58 = target->unknown40 - 1;
    target->unknown68 = 0;
    target->unknown60 = 4;
    target->unknown8 = result;
}

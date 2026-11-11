/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 102 of the vtable at 0x16bb0c0 (its pointer at
 * 0x16bb400; the family of FUN_00da7fa0, slot 75, home BytecodeReader.cpp):
 * resets the record the pointer at +0x16f0 of the record at +0x7dc8 points
 * to: the kind 5 at +0x0, -1 at +0x38 and +0x3c,
 * the pointers at +0x50 and +0x58 to the buffer at +0x40 and the byte before
 * it, 3 at +0x60 and 0 at +0x68, then its float argument at +0x8. Class and method unknown; the fields' types
 * beyond their widths are not traced. */
struct Target00da8f40 { /* derived name */
    int unknown0;       /* +0x0: the kind */
    u8 unknown4[4];
    float unknown8; /* +0x8 */
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

struct Record00da8f40 { /* derived name */
    u8 unknown0[0x16f0];
    Target00da8f40 *unknown16f0;
};

struct Object00da8f40 { /* derived name */
    u8 unknown0[0x7dc8];
    Record00da8f40 *unknown7dc8;
};

void FUN_00da8f40(Object00da8f40 *self, float value) /* derived name */
{
    Target00da8f40 *target = self->unknown7dc8->unknown16f0;
    target->unknown0 = 5;
    target->unknown38 = -1;
    target->unknown3c = -1;
    target->unknown50 = target->unknown40;
    target->unknown58 = target->unknown40 - 1;
    target->unknown60 = 3;
    target->unknown68 = 0;
    target->unknown8 = value;
}

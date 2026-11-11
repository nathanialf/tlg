/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slots 105 to 107 of the vtable at 0x16bb0c0 (their pointers
 * at 0x16bb418 to 0x16bb428; the family of FUN_00da8f40, slot 102): reset the
 * record the pointer at +0x16f0 of the record at +0x7dc8 points to, as
 * FUN_00da8f40 does, with the kinds 1, 2 and 3, 0 or 1 at +0x60 and zero at
 * +0x8. Class and methods unknown; the fields' types beyond their widths are
 * not traced. */
struct Target00da92f0 { /* derived name */
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

struct Record00da92f0 { /* derived name */
    u8 unknown0[0x16f0];
    Target00da92f0 *unknown16f0;
};

struct Object00da92f0 { /* derived name */
    u8 unknown0[0x7dc8];
    Record00da92f0 *unknown7dc8;
};

void FUN_00da92f0(Object00da92f0 *self) /* derived name */
{
    Target00da92f0 *target = self->unknown7dc8->unknown16f0;
    target->unknown0 = 1;
    target->unknown38 = -1;
    target->unknown3c = -1;
    target->unknown50 = target->unknown40;
    target->unknown58 = target->unknown40 - 1;
    target->unknown68 = 0;
    target->unknown60 = 0;
    target->unknown8 = 0;
}

void FUN_00da9340(Object00da92f0 *self) /* derived name */
{
    Target00da92f0 *target = self->unknown7dc8->unknown16f0;
    target->unknown0 = 2;
    target->unknown38 = -1;
    target->unknown3c = -1;
    target->unknown50 = target->unknown40;
    target->unknown58 = target->unknown40 - 1;
    target->unknown68 = 0;
    target->unknown60 = 1;
    target->unknown8 = 0;
}

void FUN_00da9390(Object00da92f0 *self) /* derived name */
{
    Target00da92f0 *target = self->unknown7dc8->unknown16f0;
    target->unknown0 = 3;
    target->unknown38 = -1;
    target->unknown3c = -1;
    target->unknown50 = target->unknown40;
    target->unknown58 = target->unknown40 - 1;
    target->unknown68 = 0;
    target->unknown60 = 1;
    target->unknown8 = 0;
}

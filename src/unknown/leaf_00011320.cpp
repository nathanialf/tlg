/* src/unknown/: functions matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: five ints stored at +0x28..+0x38 of the object. Unknown
 * owner. */
struct FiveInts {
    u8 unknown0[0x28];
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
};

void FUN_00011320(FiveInts *self, int a, int b, int c, int d, int e) /* derived name */
{
    self->a = a;
    self->b = b;
    self->c = c;
    self->d = d;
    self->e = e;
}

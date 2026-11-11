/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16c7e50 (+0xd0 from the vtable stored at
 * 0x16c7d80) and at 0x16cc698 (+0xe0 from the one stored at 0x16cc5b8): zeroes
 * the int at +0x10, the float at +0x44 and the int at +0x40, sets the float at
 * +0x48 to 1, and when the pointer at +0x38 is set clears it and the one at
 * +0x30 (one 16-byte store); returns 1. FUN_01375590 does the same to the
 * record at +0x38 of its object. The types are not traced. */
struct State013747f0 { /* derived name */
    u8 unknown0[0x10];
    int unknown10;
    u8 unknown14[0x1c];
    void *unknown30;
    void *unknown38;
    int unknown40;
    float unknown44;
    float unknown48;
};

// NONMATCHING: the pointer at +0x38 tested as its own load (mov rax; test rax, rax) where the build folds it into `cmp qword [rdi+0x38], 0`; the stores are the base's. Unfolded is what a volatile load gives (cookbook 109), which nothing in the bytes justifies
int FUN_013747f0(State013747f0 *self) /* derived name */
{
    self->unknown10 = 0;
    self->unknown44 = 0.0f;
    self->unknown48 = 1.0f;
    self->unknown40 = 0;
    if (self->unknown38 != 0) {
        self->unknown30 = 0;
        self->unknown38 = 0;
    }
    return 1;
}

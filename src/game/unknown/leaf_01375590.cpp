/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function at 0x16c7da8 (+0x28 from the vtable stored at
 * 0x16c7d80) and at 0x16cc5e0 (+0x28 from the one stored at 0x16cc5b8): what
 * FUN_013747f0 (leaf_013747f0.cpp) does to its object, done to the record at
 * +0x38: zeroes its int at +0x10, float at +0x44 and int at +0x40, sets its
 * float at +0x48 to 1, and when its pointer at +0x38 is set clears it and the
 * one at +0x30; returns 1. The types are not traced. */
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

struct Object01375590 { /* derived name */
    u8 unknown0[0x38];
    State013747f0 unknown38;
};

// NONMATCHING: the pointer at +0x38 tested as its own load (mov rax; test rax, rax) where the build folds it into `cmp qword [rdi+0x38], 0`; the stores are the base's. Unfolded is what a volatile load gives (cookbook 109), which nothing in the bytes justifies
int FUN_01375590(Object01375590 *self) /* derived name */
{
    State013747f0 *state = &self->unknown38;
    state->unknown10 = 0;
    state->unknown44 = 0.0f;
    state->unknown48 = 1.0f;
    state->unknown40 = 0;
    if (state->unknown38 != 0) {
        state->unknown30 = 0;
        state->unknown38 = 0;
    }
    return 1;
}

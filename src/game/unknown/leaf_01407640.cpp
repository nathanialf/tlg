/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_simd.h"

/* derived names: clears the ints at +0x10 and +0x18, the 16-byte vectors at
 * +0x20 and +0x30 and the eight floats at +0x40, and sets the float at +0x60
 * to 2.1; slot 0 of the vtable at 0x16d5910 (its pointer at 0x16d5920), stored
 * by FUN_010b0530, slot 1 FUN_0140b610. The fields' meanings are not traced. */
struct Object01407640 { /* derived name */
    u8 unknown0[0x10];
    int unknown10;
    u8 unknown14[4];
    int unknown18;
    u8 unknown1c[4];
    Vec4 unknown20;
    Vec4 unknown30;
    float unknown40[8];
    float unknown60;
};

// NONMATCHING: store merging: the base clears +0x20 and +0x30 with two aligned 16-byte stores and
// +0x40 to +0x5f with one 32-byte store, the compile merges +0x20 to +0x3f into a 32-byte store as
// well; the source form of the two vectors that keeps them apart not found
void FUN_01407640(Object01407640 *self) /* derived name */
{
    self->unknown10 = 0;
    self->unknown18 = 0;
    self->unknown20 = _mm_setzero_ps();
    self->unknown30 = _mm_setzero_ps();
    for (int i = 0; i < 8; ++i)
        self->unknown40[i] = 0.0f;
    self->unknown60 = 2.1f;
}

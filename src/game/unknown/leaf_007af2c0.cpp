/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_libc.h"

/* derived names: two slots of the vtable at 0x16ade58 (config/
 * vtables.derived.base.txt; their pointers at 0x16adf20 and 0x16adf28),
 * written as free functions on their own view of the object, each acting
 * only when the int at +0x238 of the second argument is set. FUN_007af2c0
 * clears the ints at +0x58 and +0x110 and the words of the array at +0x320
 * (counted at +0x328, both reloaded after each store); FUN_007af310 copies
 * the float at +0x310 into +0xc8 of the record the pointer at +0x300 holds
 * when they differ by more than 0.0001, marking bit 0 of the record's flags
 * byte at +0x20. The fields' meaning is not traced. */
struct Argument007af2c0 /* derived name */
{
    u8 unknown0[0x238];
    int unknown238; /* +0x238 */
};

struct Record007af310 /* derived name */
{
    u8 unknown0[0x20];
    u8 unknown20; /* +0x20: flags */
    u8 unknown21[0xa7];
    float unknownc8; /* +0xc8 */
};

struct Object007af2c0 /* derived name */
{
    u8 unknown0[0x58];
    int unknown58; /* +0x58 */
    u8 unknown5c[0xb4];
    int unknown110; /* +0x110 */
    u8 unknown114[0x1ec];
    Record007af310 *unknown300; /* +0x300 */
    u8 unknown308[8];
    float unknown310; /* +0x310 */
    u8 unknown314[0xc];
    u32 *unknown320; /* +0x320 */
    u32 count328;    /* +0x328 */
};

// NONMATCHING: greedy's assignment, the array in rcx and the index in rdx where the
// base has them the other way; every instruction else equal.
void FUN_007af2c0(Object007af2c0 *self, const Argument007af2c0 *argument) /* derived name */
{
    if (argument->unknown238) {
        self->unknown58 = 0;
        self->unknown110 = 0;
        for (u32 i = 0; i < self->count328; i++)
            self->unknown320[i] = 0;
    }
}

// NONMATCHING: the inequality's branch, the build `jne; jp` (une), the base one `je`
// over the body (one, a one-sided test that skips the unordered case).
void FUN_007af310(Object007af2c0 *self, const Argument007af2c0 *argument) /* derived name */
{
    if (argument->unknown238) {
        Record007af310 *record = self->unknown300;
        const float value = self->unknown310;
        if (value != record->unknownc8 && fabsf(record->unknownc8 - value) > 0.0001f) {
            record->unknownc8 = value;
            record->unknown20 |= 1;
        }
    }
}

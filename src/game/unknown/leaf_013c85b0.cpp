/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 84 of the vtable at 0x16d2818 (its pointer at
 * 0x16d2ac8), stored by FUN_00de43d0: a byte tally as its neighbour slots
 * (FUN_013c8600). For an object that is not null whose 64-bit word at +0x0
 * shifted right by 10 is nonzero, adds that to the 64-bit total at +0x60 and
 * counts it at +0x118; then 16 bytes for each of the count at +0x30 to the
 * total at +0x70 (counted at +0x128), and 40 bytes for each of one more than
 * the count at +0x1c to the total at +0x68 (counted at +0x120), each only
 * when not zero. The object is read without the null test after the first
 * part. Class and method unknown. */
struct Object013c85b0 /* derived name */
{
    u64 unknown0; /* +0x0 */
    u8 unknown8[0x14];
    u32 unknown1c; /* +0x1c */
    u8 unknown20[0x10];
    u32 unknown30; /* +0x30 */
};

struct Tally013c85b0 /* derived name */
{
    u8 unknown0[0x60];
    u64 unknown60; /* +0x60: bytes */
    u64 unknown68; /* +0x68: bytes */
    u64 unknown70; /* +0x70: bytes */
    u8 unknown78[0xa0];
    u64 unknown118; /* +0x118: the count of +0x60 */
    u64 unknown120; /* +0x120: the count of +0x68 */
    u64 unknown128; /* +0x128: the count of +0x70 */
};

void FUN_013c85b0(Tally013c85b0 *self, const Object013c85b0 *object) /* derived name */
{
    if (object) {
        u64 size = object->unknown0 >> 10;
        if (size) {
            self->unknown60 += size;
            self->unknown118++;
        }
    }
    if (object->unknown30) {
        self->unknown70 += u64(object->unknown30) * 16;
        self->unknown128++;
    }
    u32 count = object->unknown1c + 1;
    if (count) {
        self->unknown68 += u64(count) * 40;
        self->unknown120++;
    }
}

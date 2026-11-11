/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 85 of the vtable at 0x16d2818 (its pointer at
 * 0x16d2ad0), stored by FUN_00de43d0: a byte tally. For an object that is not
 * null whose 64-bit word at +0x0 shifted right by 10 is nonzero, adds that to
 * the 64-bit total at +0x78 and counts it in the 64-bit count at +0x130; then
 * adds 0x18 plus 8 times the byte at +0x11 of the 24-byte entry, in the array
 * at +0x8 of the record the pointer at +0x18 of the object holds, that the
 * record's 64-bit word at +0x0 indexes, and counts that too. The object's
 * pointer at +0x18 is read without the null test. The sibling slot
 * FUN_013c8640 does the first part on +0x58 and +0x110. Class and method
 * unknown. */
struct Entry013c8600 /* derived name */
{
    u8 unknown0[0x11];
    u8 unknown11; /* +0x11 */
    u8 unknown12[6];
};

struct Record013c8600 /* derived name */
{
    u64 unknown0;              /* +0x0: the entry's index */
    Entry013c8600 unknown8[1]; /* +0x8 */
};

struct Object013c8600 /* derived name */
{
    u64 unknown0; /* +0x0 */
    u8 unknown8[0x10];
    Record013c8600 *unknown18; /* +0x18 */
};

struct Tally013c8600 /* derived name */
{
    u8 unknown0[0x78];
    u64 unknown78; /* +0x78: the bytes */
    u8 unknown80[0xb0];
    u64 unknown130; /* +0x130: the count */
};

void FUN_013c8600(Tally013c8600 *self, const Object013c8600 *object) /* derived name */
{
    if (object) {
        u64 size = object->unknown0 >> 10;
        if (size) {
            self->unknown78 += size;
            self->unknown130++;
        }
    }
    const Record013c8600 *record = object->unknown18;
    self->unknown78 += record->unknown8[record->unknown0].unknown11 * 8 + 0x18;
    self->unknown130++;
}

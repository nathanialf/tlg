/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_vector.h"
#include "tlg_types.h"

/* derived names: a slot of a vtable without a row (its pointer at 0x16aced8):
 * copies the int at +0x160 to +0x5110 of the record at +0x68; when the object
 * at +0x108 is set and its int at +0x58 is 0, resets the record's block at
 * +0x50e0 (0 at +0x50e0, the vector (0, 0, 0, 1) at +0x50f0, FLT_MAX at
 * +0x5100, 0 at +0x5104 and +0x5108, -1 at +0x510c, and 0 at +0x5110 again).
 * The fields' meaning is not traced. */
struct Record00777cb0 { /* derived name */
    u8 unknown0[0x50e0];
    int unknown50e0; /* +0x50e0 */
    u8 unknown50e4[0xc];
    Vector4 unknown50f0; /* +0x50f0 */
    float unknown5100;   /* +0x5100 */
    int unknown5104;     /* +0x5104 */
    int unknown5108;     /* +0x5108 */
    int unknown510c;     /* +0x510c */
    int unknown5110;     /* +0x5110 */
};

struct Member00777cb0_108 { /* derived name */
    u8 unknown0[0x58];
    int unknown58; /* +0x58 */
};

struct Object00777cb0 { /* derived name */
    u8 unknown0[0x68];
    Record00777cb0 *record; /* +0x68 */
    u8 unknown70[0x98];
    Member00777cb0_108 *unknown108; /* +0x108 */
    u8 unknown110[0x50];
    int unknown160; /* +0x160 */
};

// NONMATCHING: store merging: the base keeps the four dword stores of +0x5104 to +0x5110 (0, 0,
// -1, 0) apart, the build merges them into one 16-byte `vmovups` of a constant; and the record
// pointer is loaded before +0x160 in the base, after it here (with `self->record->unknown5110 =`
// the order is the base's but the pointer is loaded again for the block)
void FUN_00777cb0(Object00777cb0 *self) /* derived name */
{
    Record00777cb0 *record = self->record;
    record->unknown5110 = self->unknown160;
    if (self->unknown108 && !self->unknown108->unknown58) {
        record->unknown50e0 = 0;
        record->unknown50f0 = Vector4(0.0f, 0.0f, 0.0f, 1.0f);
        record->unknown5100 = 3.40282347e+38f;
        record->unknown5104 = 0;
        record->unknown5108 = 0;
        record->unknown510c = -1;
        record->unknown5110 = 0;
    }
}

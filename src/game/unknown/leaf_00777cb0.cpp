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
    float unknown5104;   /* +0x5104: a float (vmovss at 0x73a069) */
    float unknown5108;   /* +0x5108: a float (vmovss at 0x73a0cb) */
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

// NONMATCHING: store merging: the base keeps the stores of +0x5104 to +0x5110 (0.0, 0.0, -1, 0)
// one dword each; the build merges -1 and 0 at +0x510c into one qword (`mov ecx, -1` first), as the
// base itself does at 0x7190b8. Uses: +0x5104 and +0x5108 are floats (vmovss at 0x73a069, 0x73a0cb),
// which ends the four-int vector store (round 524E); +0x510c an index (movsxd at 0x776408); 0x6db539
// copies +0x5100 to +0x510f as one 16-byte vmovaps and +0x5110 apart. In the base's 0x708e11 run the
// pair stays apart because a qword store follows it (MergeConsecutiveStores starts only at the end of a
// run, 3.7.1 DAGCombiner.cpp:10873); here nothing follows.
void FUN_00777cb0(Object00777cb0 *self) /* derived name */
{
    Record00777cb0 *record = self->record;
    record->unknown5110 = self->unknown160;
    if (self->unknown108 && !self->unknown108->unknown58) {
        record->unknown50e0 = 0;
        record->unknown50f0 = Vector4(0.0f, 0.0f, 0.0f, 1.0f);
        record->unknown5100 = 3.40282347e+38f;
        record->unknown5104 = 0.0f;
        record->unknown5108 = 0.0f;
        record->unknown510c = -1;
        record->unknown5110 = 0;
    }
}

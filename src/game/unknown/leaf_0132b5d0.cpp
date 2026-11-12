/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: marks a slot (bit index of the byte at +0xe566) and copies 1
 * to 16 values into it (+0x404 of the slot, 0x450 bytes each from +0x0), the
 * highest first through a falling switch (the count's jump table 0x155cd58,
 * counts 1 to 16), then stores the count (+0x444) whatever it is. What the
 * slots hold is not traced. */
struct Slot0132b5d0 { /* derived name */
    u8 unknown0[0x404];
    float values[16]; /* +0x404 */
    int count;        /* +0x444 */
    u8 unknown448[0x8];
};

struct Owner0132b5d0 { /* derived name */
    Slot0132b5d0 slots[8];
    u8 unknown2280[0xe566 - 0x2280];
    u8 dirty; /* +0xe566 */
};

// NONMATCHING: greedy's assignment: the slot's offset in r9 (the stores carry REX, 255 bytes)
// and the count in r8 where the build has rcx and r9 (238 bytes); the entry's order follows
void FUN_0132b5d0(Owner0132b5d0 *self, unsigned index, const float *values,
                  int count) /* derived name */
{
    self->dirty |= 1 << index;
    Slot0132b5d0 &slot = self->slots[index];
    float *target = slot.values;
    switch (count) {
    case 16:
        target[15] = values[15];
        // fall through
    case 15:
        target[14] = values[14];
        // fall through
    case 14:
        target[13] = values[13];
        // fall through
    case 13:
        target[12] = values[12];
        // fall through
    case 12:
        target[11] = values[11];
        // fall through
    case 11:
        target[10] = values[10];
        // fall through
    case 10:
        target[9] = values[9];
        // fall through
    case 9:
        target[8] = values[8];
        // fall through
    case 8:
        target[7] = values[7];
        // fall through
    case 7:
        target[6] = values[6];
        // fall through
    case 6:
        target[5] = values[5];
        // fall through
    case 5:
        target[4] = values[4];
        // fall through
    case 4:
        target[3] = values[3];
        // fall through
    case 3:
        target[2] = values[2];
        // fall through
    case 2:
        target[1] = values[1];
        // fall through
    case 1:
        target[0] = values[0];
    }
    slot.count = count;
}

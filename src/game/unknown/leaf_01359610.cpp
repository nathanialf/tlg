/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a 0x30-byte slot whose handle at +0x8 is -1 while it is
 * unused */
struct Slot01359610 { /* derived name */
    u8 unknown0[0x8];
    s64 handle; /* +0x8 */
    u8 unknown10[0x20];
};

/* derived names: a record of four channels (FUN_01359610 resets it; called
 * by FUN_00547030 and FUN_011e5e50) */
struct Record01359610 {         /* derived name */
    float scales[4];            /* +0x0: 1 where the slot is unused */
    Slot01359610 slots[4];      /* +0x10 */
    int unknownD0;              /* +0xd0 */
    int unknownD4;              /* +0xd4 */
    int pairValues[2];          /* +0xd8: 0 where the pair's slot is unused */
    Slot01359610 pairSlots[2];  /* +0xe0 */
    float limits[4];            /* +0x140: -1 where the slot is unused */
    Slot01359610 limitSlots[4]; /* +0x150 */
    int unknown210;             /* +0x210 */
    int unknown214;             /* +0x214 */
    u8 unknown218[0x60];
    float unknown278[4]; /* +0x278 */
    u8 unknown288[0xc0];
    int unknown348; /* +0x348 */
    u8 unknown34c[0x34];
    int unknown380; /* +0x380 */
    u8 unknown384[0x34];
    int unknown3b8[4]; /* +0x3b8 */
    int unknown3c8[4]; /* +0x3c8: 3 */
    s64 unknown3d8;    /* +0x3d8 */
    int unknown3e0;    /* +0x3e0 */
    int unknown3e4[4]; /* +0x3e4 */
    float weights[4];  /* +0x3f4: 1 */
};

void FUN_01359610(Record01359610 *self) /* derived name */
{
    self->unknownD0 = 0;
    self->unknownD4 = 0;
    self->unknown348 = 0;
    self->unknown380 = 0;
    self->unknown3d8 = 0;
    self->unknown3e0 = 0;
    for (int i = 0; i < 2; ++i) {
        if (self->pairSlots[i].handle == -1)
            self->pairValues[i] = 0;
    }
    for (int i = 0; i < 4; ++i) {
        if (self->slots[i].handle == -1)
            self->scales[i] = 1.0f;
        if (self->limitSlots[i].handle == -1)
            self->limits[i] = -1.0f;
        self->unknown3b8[i] = 0;
        self->unknown3c8[i] = 3;
        self->unknown3e4[i] = 0;
        self->weights[i] = 1.0f;
    }
    self->unknown214 = 0;
    self->unknown210 = 0;
    for (int i = 0; i < 4; ++i)
        self->unknown278[i] = 0.0f;
}

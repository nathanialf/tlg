/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: six entries of the table of function pointers at 0x16c5590
 * (entries 56, 100, 102, 108, 112 and 148; 58 is FUN_0132c500 and 110
 * FUN_0132c680): each writes one value of a shader's user data, selected by
 * the 4-byte slot entry its second argument indexes in the record's array at
 * +0x0 (the register at its byte +0x2). The entries that write a packet put
 * it into the graphics command buffer at +0x0 of their first argument: a
 * type-3 set-shader-register packet (0xc0017600 for one data dword,
 * 0xc0027600 for two; bit 1 set for the stage 0), the register's offset from
 * 0x2c00 being the stage's first user-data register (the 16-bit table at
 * 0x15cf6f0) plus the slot's. The entries that do not write a packet store
 * the value in the record's dword array at +0x18 at the slot's register less
 * 16. The command buffer is FUN_0132f4f0's (the end at +0x8, the write
 * position at +0x10, the function at +0x18 that makes room). */

extern const u16 D_15cf6f0[]; /* the first user-data register of each stage */

struct CommandBuffer0132c450 { /* derived name */

    bool reserve(u32 dwords) /* derived name */
    {
        if (static_cast<u32>(end - cmd) < dwords)
            return makeRoom(this, dwords, userData);
        return true;
    }

    /* derived name: one dword into a user-data register */
    void setUserData(u32 stage, u32 slot, u32 value)
    {
        if (reserve(3)) {
            u32 *packet = cmd;
            u32 first = D_15cf6f0[stage];
            packet[0] = 0xc0017600 | (stage == 0) << 1;
            packet[1] = first + slot - 0x2c00;
            packet[2] = value;
            cmd = packet + 3;
        }
    }

    /* derived name: an address into two user-data registers */
    void setPointerInUserData(u32 stage, u32 slot, const void *address)
    {
        if (reserve(4)) {
            u32 *packet = cmd;
            u64 bits = reinterpret_cast<u64>(address);
            u32 header = 0xc0027600 | (stage == 0) << 1;
            u32 first = D_15cf6f0[stage];
            u32 high = static_cast<u32>(bits >> 32);
            packet[0] = header;
            packet[1] = first + slot - 0x2c00;
            packet[2] = static_cast<u32>(bits);
            packet[3] = high;
            cmd += 4;
        }
    }

    u32 *begin; /* +0x0: not read here */
    u32 *end;   /* +0x8 */
    u32 *cmd;   /* +0x10 */
    bool (*makeRoom)(CommandBuffer0132c450 *buffer, u32 dwords, void *userData); /* +0x18 */
    void *userData;                                                              /* +0x20 */
};

struct Slot0132c450 { /* derived name */
    u8 unknown0[2];
    u8 startRegister; /* +0x2 */
    u8 unknown3;
};

struct Record0132c450 {        /* derived name */
    const Slot0132c450 *slots; /* +0x0 */
    u32 stage;                 /* +0x8 */
    u8 unknownc[0xc];
    u32 *userData; /* +0x18 */
};

/* derived name: the 24-byte entries FUN_0132b6d0 walks (two 16-bit masks at
 * +0x0 and +0x2, pointers at +0x8 and +0x10) */
struct Block0132b6d0 {
    u16 unknown0;
    u16 unknown2;
    u8 unknown4[4];
    void *unknown8;  /* +0x8 */
    void *unknown10; /* +0x10 */
};

void FUN_0132b6d0(Block0132b6d0 *blocks, u32 count);

struct Object0132c450 {              /* derived name */
    CommandBuffer0132c450 *commands; /* +0x0 */
    u8 unknown8[0xe3e0];
    Block0132b6d0 blockE3e8; /* +0xe3e8 */
    u8 unknownE400[0x88];
    void *unknownE488; /* +0xe488 */
    u8 unknownE490[0xcf];
    bool unknownE55f; /* +0xe55f: set by entry 102 */
    u16 unknownE560;  /* +0xe560 */
    u16 unknownE562;  /* +0xe562 */
    u8 unknownE564[0x14];
    void *unknownE578; /* +0xe578 */
};

// NONMATCHING: the register's sum: the base forms `lea edx, [slot + first - 0x2c00]`
// (the slot's byte as the base register), the build `lea ecx, [first + slot - 0x2c00]`:
// Reassociate ranks the table's load in the packet's block above the slot's load in
// the entry, so the slot pairs with the constant; written as either sum, a bit field
// or the table read before the reservation, the same.
/* entry 56: four times the product of the 16-bit values at +0xe560 and +0xe562 */
void FUN_0132c450(Object0132c450 *self, u32 index, Record0132c450 *record) /* derived name */
{
    u32 slot = record->slots[index].startRegister;
    self->commands->setUserData(record->stage, slot, self->unknownE560 * self->unknownE562 * 4);
}

// NONMATCHING: the register's sum: the base forms `lea edx, [slot + first - 0x2c00]`
// (the slot's byte as the base register), the build `lea ecx, [first + slot - 0x2c00]`:
// Reassociate ranks the table's load in the packet's block above the slot's load in
// the entry, so the slot pairs with the constant; written as either sum, a bit field
// or the table read before the reservation, the same.
/* entry 112: the record's own user-data array, when it has one */
void FUN_0132c540(Object0132c450 *self, u32 index, Record0132c450 *record) /* derived name */
{
    u32 *userData = record->userData;
    if (userData) {
        u32 slot = record->slots[index].startRegister;
        self->commands->setPointerInUserData(record->stage, slot, userData);
    }
}

// NONMATCHING: the register's sum: the base forms `lea edx, [slot + first - 0x2c00]`
// (the slot's byte as the base register), the build `lea ecx, [first + slot - 0x2c00]`:
// Reassociate ranks the table's load in the packet's block above the slot's load in
// the entry, so the slot pairs with the constant; written as either sum, a bit field
// or the table read before the reservation, the same.
/* entry 108: the pointer at +0xe488 */
void FUN_0132c5e0(Object0132c450 *self, u32 index, Record0132c450 *record) /* derived name */
{
    u32 slot = record->slots[index].startRegister;
    self->commands->setPointerInUserData(record->stage, slot, self->unknownE488);
}

// NONMATCHING: the register's sum: the base forms `lea edx, [slot + first - 0x2c00]`
// (the slot's byte as the base register), the build `lea ecx, [first + slot - 0x2c00]`:
// Reassociate ranks the table's load in the packet's block above the slot's load in
// the entry, so the slot pairs with the constant; written as either sum, a bit field
// or the table read before the reservation, the same.
/* entry 148: the pointer at +0xe578 */
void FUN_0132c6b0(Object0132c450 *self, u32 index, Record0132c450 *record) /* derived name */
{
    u32 slot = record->slots[index].startRegister;
    self->commands->setPointerInUserData(record->stage, slot, self->unknownE578);
}

// NONMATCHING: the register's sum: the base forms `lea edx, [slot + first - 0x2c00]`
// (the slot's byte as the base register), the build `lea ecx, [first + slot - 0x2c00]`:
// Reassociate ranks the table's load in the packet's block above the slot's load in
// the entry, so the slot pairs with the constant; written as either sum, a bit field
// or the table read before the reservation, the same.
/* entry 100: the block at +0xe3e8 brought up to date, then its pointer at +0x8 */
void FUN_0132c750(Object0132c450 *self, u32 index, Record0132c450 *record) /* derived name */
{
    u32 slot = record->slots[index].startRegister;
    FUN_0132b6d0(&self->blockE3e8, 1);
    self->commands->setPointerInUserData(record->stage, slot, self->blockE3e8.unknown8);
}

/* entry 102: as entry 100, the pointer stored in the record's array */
void FUN_0132c800(Object0132c450 *self, u32 index, Record0132c450 *record) /* derived name */
{
    void **target =
        reinterpret_cast<void **>(&record->userData[record->slots[index].startRegister - 16u]);
    FUN_0132b6d0(&self->blockE3e8, 1);
    *target = self->blockE3e8.unknown8;
    self->unknownE55f = true;
}

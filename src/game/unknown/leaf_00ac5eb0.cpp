/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: slot 7 of a soldier AI mode, slot 7 of the vtable at
 * 0x16b36e0 (slot 2 is FUN_00ac3390): given another mode that is not of
 * kind 13 (its int at +0x10), when the soldier the owner (+0x8) holds first
 * has its byte at +0x49b set and a subtype (as leaf_0046d150.cpp's: its own
 * name at +0x39c, else the name at +0x58 of the record FUN_002a45c0 finds
 * for the key at 0x57d5304 in its entity, else the name at 0x57d4f60), hands
 * the subtype's index to FUN_004bc570 with 2 and 0, the subtype worked out
 * again. The types are not traced beyond these fields. */
struct Entity00ac5eb0; /* derived name */

struct Record002a45c0 { /* derived name */
    u8 unknown0[0x58];
    Name name; /* +0x58 */
};

struct Soldier00ac5eb0 { /* derived name */
    u8 unknown0[0x28];
    Entity00ac5eb0 *entity; /* +0x28 */
    u8 unknown30[0x36c];
    Name subtype; /* +0x39c */
    u8 unknown3a0[0xfb];
    bool unknown49b; /* +0x49b */
};

struct Owner00ac5eb0 {        /* derived name */
    Soldier00ac5eb0 *soldier; /* +0x0 */
};

struct Mode00ac5eb0 { /* derived name */
    u8 unknown0[0x8];
    Owner00ac5eb0 *unknown8; /* +0x8: the owner */
    int unknown10;           /* +0x10: the mode's kind */
};

extern const Name D_57d5304; /* derived name: the key of a soldier's subtype record */
extern const Name D_57d4f60; /* derived name: the subtype of a soldier without one */

Record002a45c0 *FUN_002a45c0(Entity00ac5eb0 *entity, const Name *key,
                             int unknown2);                   /* derived name */
void FUN_004bc570(unsigned name, int unknown1, int unknown2); /* derived name */

/* derived name: the soldier's subtype */
static inline const Name &subtypeOf(const Soldier00ac5eb0 *soldier)
{
    if (soldier->subtype.index != 0)
        return soldier->subtype;
    const Record002a45c0 *record = FUN_002a45c0(soldier->entity, &D_57d5304, 1);
    return record ? record->name : D_57d4f60;
}

// NONMATCHING: the second subtype's select: the build keeps the fallback's
// address in r14 and moves the record's name into it (`cmovne r14, rax; mov
// edi, [r14]`), the base the other way (`cmove rax, r14; mov edi, [rax]`),
// one byte shorter; everything before it equal
void FUN_00ac5eb0(Mode00ac5eb0 *self, const Mode00ac5eb0 *next) /* derived name */
{
    if (!next || next->unknown10 == 13)
        return;
    const Soldier00ac5eb0 *soldier = self->unknown8->soldier;
    if (!soldier->unknown49b)
        return;
    if (subtypeOf(soldier).index == 0)
        return;
    FUN_004bc570(subtypeOf(soldier).index, 2, 0);
}

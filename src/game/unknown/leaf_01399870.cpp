/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a virtual method (its address at 0x16cfd90): for the
 * group at index of the 64-byte groups at +0x20 of the record at +0x20, and
 * of its 24-byte lists the one the record's int at +0x10 picks, copies for
 * each of the list's indices eight words of the 0x2c-byte source entry the
 * index picks (+0xc to +0x28; the entries at +0x18 of the record at +0x30) to
 * the 64-byte destination entry of the output's array at +0x28, in the
 * order +0x0, +0x4, +0x10, +0x14, +0x8, +0xc, +0x18, +0x1c. The third
 * parameter is unused; the classes are not traced. */
struct Source01399870 { /* derived name */
    u8 unknown0[0xc];
    int unknownc[8]; /* +0xc */
};

struct Destination01399870 { /* derived name */
    int unknown0[8];         /* +0x0 */
    u8 unknown20[0x20];
};

struct List01399870 {        /* derived name */
    const unsigned *indices; /* +0x0 */
    int count;               /* +0x8 */
    u8 unknownc[0xc];
};

struct Group01399870 {     /* derived name */
    List01399870 lists[1]; /* its extent not traced: 64 bytes in all */
    u8 unknown18[0x28];
};

struct Record01399870 { /* derived name */
    u8 unknown0[0x10];
    unsigned list; /* +0x10 */
    u8 unknown14[0xc];
    Group01399870 *groups; /* +0x20 */
};

struct Table01399870 { /* derived name */
    u8 unknown0[0x18];
    const Source01399870 *entries; /* +0x18 */
};

struct Object01399870 { /* derived name */
    u8 unknown0[0x20];
    Record01399870 *record; /* +0x20 */
    u8 unknown28[8];
    Table01399870 *table; /* +0x30 */
};

struct Output01399870 { /* derived name */
    u8 unknown0[0x28];
    Destination01399870 *entries; /* +0x28 */
};

// NONMATCHING: the base holds the destination at +0x1c (LoopStrengthReduce's base, the stores at -0x1c to 0) and the group's address in rdi, the build at +0 and in rdx; the cause is not found
void FUN_01399870(Object01399870 *self, Output01399870 *output, void *,
                  int index) /* derived name */
{
    const Source01399870 *entries = self->table->entries;
    if (!entries)
        return;
    const List01399870 &list = self->record->groups[index].lists[self->record->list];
    int count = list.count;
    if (count == 0)
        return;
    Destination01399870 *destination = output->entries;
    const unsigned *indices = list.indices;
    do {
        const Source01399870 &source = entries[*indices++];
        destination->unknown0[0] = source.unknownc[0];
        destination->unknown0[1] = source.unknownc[1];
        destination->unknown0[4] = source.unknownc[2];
        destination->unknown0[5] = source.unknownc[3];
        destination->unknown0[2] = source.unknownc[4];
        destination->unknown0[3] = source.unknownc[5];
        destination->unknown0[6] = source.unknownc[6];
        destination->unknown0[7] = source.unknownc[7];
        ++destination;
    } while (--count != 0);
}

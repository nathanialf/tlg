/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_simd.h"

/* derived names: two counted objects handed over together; FUN_00c68570
 * builds one on its stack from the references at +0x0 and +0x8 of each of
 * its records (Record013a9af0: one 16-byte copy) and passes its address */
struct Held00d2fa60 { /* derived name: each pointer copied, then given its reference */
    Object016b9108 *first;
    Object016b9108 *second;
};

/* derived names: two vectors (FUN_00c68570 passes +0x10 of its record),
 * copied into the record one at a time (two aligned 16-byte copies; the
 * struct assigned whole is one 32-byte memcpy, `vmovups ymm0`) */
struct Pair00d2fa60 { /* derived name */
    Vec4 first;
    Vec4 second;
};

/* derived names: a record of 0x50 bytes taken from its owner's arena; only
 * its name is constructed, the rest is filled by its maker */
struct Record00d2fa60 { /* derived name */
    Vec4 first;         /* +0x0 */
    Vec4 second;        /* +0x10 */
    Held00d2fa60 held;  /* +0x20: each holds a reference */
    void *unknown30;    /* +0x30 */
    Name name;          /* +0x38 */
    int unknown3c;      /* +0x3c */
    int unknown40;      /* +0x40 */
    int unknown44;      /* +0x44 */
    u8 unknown48[0x8];
};

/* derived names: the lists the owner's records go to, at +0x31e20 of the
 * owner; this record's at +0x688 (the arena records of the siblings
 * FUN_00d2f2f0 and on go to the arrays beside it) */
struct Lists00d2fa60 { /* derived name */
    u8 unknown0[0x688];
    Array05943280<Record00d2fa60 *> records; /* +0x688 */
};

/* derived names: the owner: a bump arena at +0x5b8, whose blocks start on 16
 * bytes, a count of the records made at +0x29de0 and the lists at +0x31e20 */
struct Owner00d2fa60 { /* derived name */
    u8 unknown0[0x5b8];
    u8 *arena; /* +0x5b8 */
    u8 unknown5c0[0x29de0 - 0x5c0];
    int records; /* +0x29de0 */
    u8 unknown29de4[0x31e20 - 0x29de4];
    Lists00d2fa60 *lists; /* +0x31e20 */
};

/* derived name: a record made in the owner's arena, counted and listed, then
 * filled: its +0x44, the name, the two ints, the pointer, the two objects
 * (each given a reference) and the two vectors */
void FUN_00d2fa60(Owner00d2fa60 *owner, const Name &name, int a, int b, void *pointer,
                  const Held00d2fa60 &held, const Pair00d2fa60 &vectors, int c) /* derived name */
{
    u8 *memory = reinterpret_cast<u8 *>((reinterpret_cast<u64>(owner->arena) + 15) & ~u64(15));
    owner->arena = memory + sizeof(Record00d2fa60);
    Record00d2fa60 *record = new (memory) Record00d2fa60;
    ++owner->records;
    owner->lists->records.push(record);
    record->unknown44 = c;
    record->name = name;
    record->unknown3c = a;
    record->unknown40 = b;
    record->unknown30 = pointer;
    record->held.first = held.first;
    record->held.second = held.second;
    if (record->held.first)
        addReference(record->held.first);
    if (record->held.second)
        addReference(record->held.second);
    record->first = vectors.first;
    record->second = vectors.second;
}

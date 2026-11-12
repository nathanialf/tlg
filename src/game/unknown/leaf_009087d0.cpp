/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a table of 0x1c-byte entries keyed by an unsigned at +0x18,
 * hashed by Thomas Wang's 32-bit integer hash into a power-of-two array of
 * 16-bit heads (+0x8), chained through a 16-bit next array (+0x10), 0xffff
 * ending a chain; the entries are taken in order (+0x20 the count used, +0x18
 * the capacity). FUN_009087d0 finds a key's entry or takes a fresh one with
 * its three ints cleared at the head of its chain, null when the table is
 * full; called from 0x9137b4 and nine other sites. */
struct HashEntry009087d0 { /* derived name */
    u8 unknown0[0xc];
    int unknownC;  /* +0xc */
    int unknown10; /* +0x10 */
    int unknown14; /* +0x14 */
    u32 key;       /* +0x18 */
};

struct HashTable009087d0 {      /* derived name */
    HashEntry009087d0 *entries; /* +0x0 */
    u16 *heads;                 /* +0x8 */
    u16 *next;                  /* +0x10 */
    int capacity;               /* +0x18 */
    u32 headCount;              /* +0x1c */
    int used;                   /* +0x20 */
};

// NONMATCHING: list-ilp order (the base loads the head count first and the heads only at
// their use, the build the heads first) and `lea` against `mov; inc` both ways (the base
// `mov eax, edx; inc eax` for the count, `lea rax, [rdx + rcx]` for the entry; the build
// `lea eax, [rdx + 1]` and `add rax, rdx`); the stores and the rest in the base's order
HashEntry009087d0 *FUN_009087d0(HashTable009087d0 *table, u32 key) /* derived name */
{
    u32 hash = key;
    hash += ~(hash << 15);
    hash ^= hash >> 10;
    hash += hash << 3;
    hash ^= hash >> 6;
    hash += ~(hash << 11);
    hash ^= hash >> 16;
    u32 head = hash & (table->headCount - 1);
    for (u16 i = table->heads[head]; i != 0xffff; i = table->next[i]) {
        if (table->entries[i].key == key)
            return &table->entries[i];
    }
    if (table->used >= table->capacity)
        return 0;
    u16 index = static_cast<u16>(table->used++);
    HashEntry009087d0 *entry = &table->entries[index];
    entry->unknownC = 0;
    entry->unknown10 = 0;
    entry->key = key;
    entry->unknown14 = 0;
    table->next[index] = table->heads[head];
    table->heads[head] = index;
    return entry;
}

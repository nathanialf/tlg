/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>
#include <stdlib.h>

#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00abf000 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then the table of 7 names with a number
 * each at 0x582af20 (15 to 21), ended by the empty name with -1, destroyed by
 * the array destructor the compiler writes for it (0xabf2b0). FUN_00abec90
 * reads the table into a table of 16 buckets (the layout FUN_00abef20,
 * leaf_00abef20.cpp, destroys); what the numbers mean is not traced. */

extern const char D_15a7af8[16];
extern const char D_15a7b08[21];
extern const char D_15a7b1d[27];
extern const char D_15a7b38[22];
extern const char D_15a7b4e[24];
extern const char D_15a7b66[29];
extern const char D_15a7b83[16];

struct Entry00abf000 { /* derived name */
    Name name;         /* +0x0 */
    int value;         /* +0x4 */
};

static Entry00abf000 D_582af20[] = {
    {Name(D_15a7af8, false), 15}, {Name(D_15a7b08, false), 16},
    {Name(D_15a7b1d, false), 17}, {Name(D_15a7b38, false), 18},
    {Name(D_15a7b4e, false), 19}, {Name(D_15a7b66, false), 20},
    {Name(D_15a7b83, false), 21}, {Name(), -1},
};

/* one entry of the table, 0x18 bytes: the key, the name, the number and the
 * next entry of the bucket or of the free list */
struct NumberEntry00abec90 {   /* derived name */
    u32 hash;                  /* +0x0 */
    Name name;                 /* +0x4 */
    int value;                 /* +0x8 */
    NumberEntry00abec90 *next; /* +0x10 */
};

/* a block of entries: the first entry's address, the next block, then the
 * entries */
struct NumberBlock00abec90 {      /* derived name */
    NumberEntry00abec90 *entries; /* +0x0 */
    NumberBlock00abec90 *next;    /* +0x8 */
};

/* derived names: a table of 16 buckets keyed by a name's index, its entries
 * taken from blocks of `perBlock` entries of `entrySize` bytes */
class NumberTable00abec90 /* derived name */
{
  public:
    NumberTable00abec90() : blocks(0), freeList(0)
    {
        for (size_t i = 0; i < 16; ++i)
            buckets[i] = 0;
        perBlock = 16;
        entrySize = sizeof(NumberEntry00abec90);
        count = 0;
    }

    NumberEntry00abec90 *find(u32 hash) const
    {
        for (NumberEntry00abec90 *entry = buckets[hash % 16]; entry; entry = entry->next) {
            if (entry->hash == hash)
                return entry;
        }
        return 0;
    }

    /* the entry of a key given the number, or a new entry made for the key,
     * its name and the number at the head of its bucket */
    void set(u32 hash, const Name &name, int value)
    {
        NumberEntry00abec90 **bucket = &buckets[hash % 16];
        for (NumberEntry00abec90 *entry = *bucket; entry; entry = entry->next) {
            if (entry->hash == hash) {
                entry->value = value;
                return;
            }
        }
        NumberEntry00abec90 *entry = allocate();
        entry->hash = hash;
        entry->name = name;
        entry->value = value;
        entry->next = *bucket;
        *bucket = entry;
        ++count;
    }

    /* a key's entry made unless the key has one */
    void add(u32 hash, const Name &name, int value)
    {
        if (!find(hash))
            set(hash, name, value);
    }

  private:
    /* the entry `index` entries of `size` bytes after the first */
    static NumberEntry00abec90 *entryAt(NumberEntry00abec90 *entries, u32 index, u32 size)
    {
        return (NumberEntry00abec90 *)((u8 *)entries + index * size);
    }

    /* a free entry: the head of the free list, or the first of a new block
     * whose other entries become the free list */
    NumberEntry00abec90 *allocate()
    {
        if (NumberEntry00abec90 *entry = freeList) {
            freeList = entry->next;
            return new (entry) NumberEntry00abec90;
        }
        u32 n = perBlock;
        u32 size = entrySize;
        NumberBlock00abec90 *block =
            (NumberBlock00abec90 *)malloc(n * size + sizeof(NumberBlock00abec90));
        block->next = blocks;
        blocks = block;
        NumberEntry00abec90 *entries = (NumberEntry00abec90 *)(block + 1);
        block->entries = entries;
        if (n) {
            u32 i = 0;
            for (; i < n - 1; ++i)
                entryAt(entries, i, size)->next = entryAt(entries, i + 1, size);
            entries[i].next = 0;
        }
        NumberEntry00abec90 *entry = entries;
        freeList = entry->next;
        return new (entry) NumberEntry00abec90;
    }

    NumberEntry00abec90 *buckets[16]; /* +0x0 */
    NumberBlock00abec90 *blocks;      /* +0x80 */
    NumberEntry00abec90 *freeList;    /* +0x88 */
    u32 perBlock;                     /* +0x90 */
    u32 entrySize;                    /* +0x94 */
    u32 count;                        /* +0x98 */
};

/* FUN_00abec90: a new table holding each name of the table with its number,
 * the first entry of a name kept */
// NONMATCHING: FUN_00abec90: the base keeps the bucket's address (`lea rsi`
// on both ways into the allocation) and the new entry's next field (`lea r9`
// in each arm) as values; the build folds both into the stores' addressing
// (`[rbx + 8*r13]`, `[r14 + 0x10]`), keeping the bucket index live instead.
NumberTable00abec90 *FUN_00abec90() /* derived name */
{
    NumberTable00abec90 *table = new NumberTable00abec90;
    for (int i = 0; D_582af20[i].name.index != 0; ++i)
        table->add(D_582af20[i].name.index, D_582af20[i].name, D_582af20[i].value);
    return table;
}

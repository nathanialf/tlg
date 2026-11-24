/* src/include/tlg_game_nametable.h: a table of named entries with a fixed
 * number of buckets over blocks of entries it allocated (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_NAMETABLE_H
#define TLG_GAME_NAMETABLE_H

#include <stdlib.h>

#include "new"
#include "tlg_game_name.h"
#include "tlg_types.h"

/* derived names: the layout of Table01352a50 (tlg_game_table01352a50.h)
 * and Table00abef20 (leaf_00abef20.cpp, whose destructor this is), over an
 * entry type E with its next entry in `next`: the buckets at +0x0, the
 * list of blocks of entries after them, the free entries' list 8 bytes
 * later and the number of entries 0x18 bytes after the buckets. A block
 * holds its first entry at +0x0, links the next block at +0x8 and its
 * entries follow it (allocate()). */
struct NameTableBlock {   /* derived name */
    void *first;          /* +0x0 */
    NameTableBlock *next; /* +0x8 */
};

template <class E, size_t N> class NameTable /* derived name */
{
  public:
    /* empty: the buckets and the two lists cleared (one memset with them),
     * then the number of buckets and the entry's size (`mov dword
     * [rbx+0xb8], 0x10; mov dword [rbx+0xbc], 0x30` at 0xae64c1 for 16
     * buckets of 0x30-byte entries) and the count */
    NameTable() : buckets(), blocks(0), freeList(0), bucketCount(N), entrySize(sizeof(E)), count(0)
    {
    }

    /* with entries left they are emptied, then every block freed */
    ~NameTable()
    {
        if (count)
            clear();
        while (blocks) {
            NameTableBlock *block = blocks;
            blocks = block->next;
            free(block);
        }
    }

    /* every entry of every bucket destroyed (the next read first) and put
     * at the head of the free list, each bucket cleared after its entries,
     * then the count */
    void clear()
    {
        for (size_t i = 0; i < N; ++i) {
            E *entry = buckets[i];
            while (entry) {
                E *next = entry->next;
                entry->~E();
                entry->next = freeList;
                freeList = entry;
                entry = next;
            }
            buckets[i] = 0;
        }
        count = 0;
    }

    /* the entry of a name whose hash is its index (the bucket by the index's
     * low bits, the hash then the name compared: FUN_0052c500), null for
     * none */
    E *find(unsigned index) const
    {
        for (E *entry = buckets[index % N]; entry; entry = entry->next)
            if (entry->hash == index && entry->name.index == index)
                return entry;
        return 0;
    }

    /* the value of a name set: its entry's when the hash and the name are
     * there (the name's index read once, before the bucket's walk), else a
     * new entry made with the name and the value and put at the head of its
     * bucket (FUN_0057fa50, FUN_00d10ca0, FUN_00c7abc0) */
    template <class V> void set(const Name &name, unsigned hash, V value)
    {
        for (E *entry = buckets[hash % N]; entry; entry = entry->next)
            if (entry->hash == hash && entry->name.index == name.index) {
                entry->value = value;
                return;
            }
        E *entry = allocate();
        entry->hash = hash;
        entry->name = name;
        entry->value = value;
        entry->next = buckets[hash % N];
        buckets[hash % N] = entry;
        ++count;
    }

    /* the number of entries (FUN_008edad0 makes a script table with room
     * for them) */
    u32 size() const /* derived name */
    {
        return count;
    }

    /* derived names: a walk over every entry, bucket by bucket from the
     * first: next() answers the entry it stands on, null at the end, and
     * moves on first, to the entry's next or the first of the buckets after
     * it (FUN_008edad0) */
    class Iterator
    {
      public:
        explicit Iterator(const NameTable &table) : table(table), bucket(0), entry(0)
        {
            nextBucket();
        }

        E *next()
        {
            E *current = entry;
            if (current) {
                entry = current->next;
                if (!entry)
                    nextBucket();
            }
            return current;
        }

      private:
        void nextBucket()
        {
            while (!entry && bucket < N)
                entry = table.buckets[bucket++];
        }

        const NameTable &table;
        unsigned bucket;
        E *entry;
    };

  private:
    /* an empty entry: the head of the free list, or the first of a new
     * block of bucketCount entries of entrySize bytes, each linked to the
     * one after it (offsets in 32 bits: `lea edx, [r13+rdx]`), the rest put
     * on the free list. The block's memory is fresh, so the free list read
     * through a block of no entries is undefined. */
    E *allocate()
    {
        if (E *entry = freeList) {
            freeList = entry->next;
            return new (entry) E;
        }
        unsigned n = bucketCount;
        unsigned size = entrySize;
        NameTableBlock *block = (NameTableBlock *)malloc(n * size + sizeof(NameTableBlock));
        E *first = (E *)(block + 1);
        block->next = blocks;
        blocks = block;
        block->first = first;
        if (n) {
            u8 *bytes = (u8 *)first;
            for (unsigned i = 0; i < n - 1; ++i)
                ((E *)(bytes + i * size))->next = (E *)(bytes + (i + 1) * size);
            first[n - 1].next = 0;
        }
        freeList = first->next;
        return new (first) E;
    }

    E *buckets[N];
    NameTableBlock *blocks; /* +N*8 */
    E *freeList;            /* +N*8 + 0x8 */
    u32 bucketCount;        /* +N*8 + 0x10: N */
    u32 entrySize;          /* +N*8 + 0x14: sizeof(E) */
    u32 count;              /* +N*8 + 0x18 */
};

#endif

/* src/include/tlg_game_nametable.h: a table of named entries with a fixed
 * number of buckets over blocks of entries it allocated (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_NAMETABLE_H
#define TLG_GAME_NAMETABLE_H

#include <stdlib.h>

#include "tlg_types.h"

/* derived names: the layout of Table01352a50 (tlg_game_table01352a50.h)
 * and Table00abef20 (leaf_00abef20.cpp, whose destructor this is), over an
 * entry type E with its next entry in `next`: the buckets at +0x0, the
 * list of blocks of entries after them, the free entries' list 8 bytes
 * later and the number of entries 0x18 bytes after the buckets. A block
 * links the next at +0x8. */
struct NameTableBlock { /* derived name */
    u8 unknown0[0x8];
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

  private:
    E *buckets[N];
    NameTableBlock *blocks; /* +N*8 */
    E *freeList;            /* +N*8 + 0x8 */
    u32 bucketCount;        /* +N*8 + 0x10: N */
    u32 entrySize;          /* +N*8 + 0x14: sizeof(E) */
    u32 count;              /* +N*8 + 0x18 */
};

#endif

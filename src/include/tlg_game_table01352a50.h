/* src/include/tlg_game_table01352a50.h: a table of counted node references
 * keyed by name, with a fixed number of buckets (game region;
 * docs/TARGETS.md). Every name here is derived. Three sizes are emptied by
 * functions of their own: 64 buckets (0x1352a50), 32 (0x13aca00) and 1,024
 * (0x135fae0). */
#ifndef TLG_GAME_TABLE01352A50_H
#define TLG_GAME_TABLE01352A50_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* one entry, 0x18 bytes: the key's hash at +0x0 (its low bits pick the
 * bucket: `and eax, 0x1f` at 0x72d13f), the name at +0x4, the reference at
 * +0x8, the next entry of the bucket (or of the free list) at +0x10. */
struct TableEntry01352a50 {            /* derived name */
    u32 hash;                          /* +0x0 */
    Name name;                         /* +0x4 */
    Ref00503fb0<Object016b9108> value; /* +0x8 */
    TableEntry01352a50 *next;          /* +0x10 */
};

/* the buckets at +0x0, the free entries' list 8 bytes after them and the
 * number of entries 0x18 bytes after them (+0x208 and +0x218 with 64
 * buckets) */
template <size_t N> class Table01352a50 /* derived name */
{
  public:
    /* every entry of every bucket destroyed (the reference released, then
     * the name) and put at the head of the free list, each bucket cleared
     * after its entries, then the count */
    void clear() /* derived name */
    {
        for (size_t i = 0; i < N; ++i) {
            TableEntry01352a50 *entry = buckets[i];
            while (entry) {
                TableEntry01352a50 *next = entry->next;
                release(entry);
                entry = next;
            }
            buckets[i] = 0;
        }
        count = 0;
    }

    /* the entry of a name and hash taken out of its bucket and released,
     * nothing done when there is none */
    void remove(unsigned name, u32 hash) /* derived name */
    {
        TableEntry01352a50 *previous = 0;
        for (TableEntry01352a50 *entry = buckets[hash % N]; entry; entry = entry->next) {
            if (entry->hash == hash && entry->name.index == name) {
                if (previous)
                    previous->next = entry->next;
                else
                    buckets[hash % N] = entry->next;
                release(entry);
                --count;
                return;
            }
            previous = entry;
        }
    }

  private:
    void release(TableEntry01352a50 *entry) /* derived name */
    {
        entry->~TableEntry01352a50();
        entry->next = freeList;
        freeList = entry;
    }

    TableEntry01352a50 *buckets[N];
    u8 unknownEnd[8];
    TableEntry01352a50 *freeList; /* +N*8 + 0x8 */
    u8 unknownEnd10[8];
    u32 count; /* +N*8 + 0x18 */
};

#endif

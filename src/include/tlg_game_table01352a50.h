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

/* one entry, 0x18 bytes: the name at +0x4, the reference at +0x8, the next
 * entry of the bucket (or of the free list) at +0x10. The word at +0x0 is
 * not traced. */
struct TableEntry01352a50 { /* derived name */
    u32 unknown0;
    Name name;                       /* +0x4 */
    Ref00503fb0<Node00503fb0> value; /* +0x8 */
    TableEntry01352a50 *next;        /* +0x10 */
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

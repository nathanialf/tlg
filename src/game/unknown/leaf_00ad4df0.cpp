/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <stdlib.h>

#include "tlg_game_name.h"

/* derived names: a table of 16 buckets of named entries over blocks of
 * entries it allocated; FUN_0047f7e0 destroys and deletes one (`call
 * 0xad4df0` then operator delete). Its layout is Table01352a50's
 * (tlg_game_table01352a50.h) with 16 buckets and its blocks' list at +0x80;
 * an entry holds nothing to release but its name. */
struct Table00ad4df0Entry { /* derived name */
    u32 hash;               /* +0x0 */
    Name name;              /* +0x4 */
    u8 unknown8[0x8];
    Table00ad4df0Entry *next; /* +0x10: the next of the bucket, or of the free list */
};

struct Table00ad4df0Block { /* derived name */
    u8 unknown0[0x8];
    Table00ad4df0Block *next; /* +0x8 */
};

class Table00ad4df0 /* derived name */
{
  public:
    ~Table00ad4df0();

  private:
    Table00ad4df0Entry *buckets[16]; /* +0x0 */
    Table00ad4df0Block *blocks;      /* +0x80 */
    Table00ad4df0Entry *freeList;    /* +0x88 */
    u8 unknown90[0x8];
    u32 count; /* +0x98 */
};

/* FUN_00ad4df0: with entries left, each bucket's entries destroyed (the name
 * released, the next read first) and put at the head of the free list, the
 * bucket cleared after them, then the count; then every block freed */
Table00ad4df0::~Table00ad4df0()
{
    if (count) {
        for (size_t i = 0; i < 16; ++i) {
            Table00ad4df0Entry *entry = buckets[i];
            while (entry) {
                Table00ad4df0Entry *next = entry->next;
                entry->~Table00ad4df0Entry();
                entry->next = freeList;
                freeList = entry;
                entry = next;
            }
            buckets[i] = 0;
        }
        count = 0;
    }
    while (blocks) {
        Table00ad4df0Block *block = blocks;
        blocks = block->next;
        free(block);
    }
}

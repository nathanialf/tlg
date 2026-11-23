/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_nametable.h"

/* derived names: an entry of the inner tables of 32 buckets, 0x18 bytes:
 * the hash, the name, 8 bytes not traced, the next */
struct InnerEntry01388db0 { /* derived name */
    u32 hash;               /* +0x0 */
    Name name;              /* +0x4 */
    u8 unknown8[0x8];
    InnerEntry01388db0 *next; /* +0x10 */
};

/* derived names: an entry of a table of 32 buckets emptied by
 * FUN_00a17930, FUN_00a17bb0, FUN_01356520 and three more: the hash, the name, a table of its own it deletes
 * (its destructor inlined, then operator delete), the next. The table is
 * deleted before the name is released. */
struct Entry01388db0 { /* derived name */

    ~Entry01388db0()
    {
        delete table;
    }

    u32 hash;                                 /* +0x0 */
    Name name;                                /* +0x4 */
    NameTable<InnerEntry01388db0, 32> *table; /* +0x8 */
    Entry01388db0 *next;                      /* +0x10 */
};

/* FUN_01388db0: every entry emptied, each inner table deleted */
template void NameTable<Entry01388db0, 32>::clear();

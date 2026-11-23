/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_nametable.h"

/* derived names: an entry of the inner tables of 24 buckets, 0x18 bytes:
 * the hash, the name, 8 bytes not traced, the next */
struct InnerEntry013481a0 { /* derived name */
    u32 hash;               /* +0x0 */
    Name name;              /* +0x4 */
    u8 unknown8[0x8];
    InnerEntry013481a0 *next; /* +0x10 */
};

/* derived names: an entry of a table of 256 buckets of the object
 * FUN_00293bf0 destroys: the hash, the name, a table of its own it deletes
 * (its destructor inlined, then operator delete), the next. The table is
 * deleted before the name is released. */
struct Entry013481a0 { /* derived name */

    ~Entry013481a0()
    {
        delete table;
    }

    u32 hash;                                 /* +0x0 */
    Name name;                                /* +0x4 */
    NameTable<InnerEntry013481a0, 24> *table; /* +0x8 */
    Entry013481a0 *next;                      /* +0x10 */
};

/* FUN_013481a0: every entry emptied, each inner table deleted */
template void NameTable<Entry013481a0, 256>::clear();

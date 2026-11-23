/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_nametable.h"

/* derived names: an entry of the inner tables of 16 buckets, 0x38 bytes:
 * the hash, the name, 0x28 bytes not traced, the next */
struct InnerEntry0138e430 { /* derived name */
    u32 hash;               /* +0x0 */
    Name name;              /* +0x4 */
    u8 unknown8[0x28];
    InnerEntry0138e430 *next; /* +0x30 */
};

/* derived names: an entry of a table of 64 buckets of the objects
 * FUN_00aa3b20 and FUN_00aa4880 destroy: the hash, the name, a table of its own it deletes
 * (its destructor inlined, then operator delete), the next. The table is
 * deleted before the name is released. */
struct Entry0138e430 { /* derived name */

    ~Entry0138e430()
    {
        delete table;
    }

    u32 hash;                                 /* +0x0 */
    Name name;                                /* +0x4 */
    NameTable<InnerEntry0138e430, 16> *table; /* +0x8 */
    Entry0138e430 *next;                      /* +0x10 */
};

/* FUN_0138e430: every entry emptied, each inner table deleted */
template void NameTable<Entry0138e430, 64>::clear();

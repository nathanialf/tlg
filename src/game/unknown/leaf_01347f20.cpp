/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_nametable.h"

/* derived names: an entry of a table of 256 buckets of the object
 * FUN_00293bf0 destroys: the hash, the name, a list of names of its own it
 * deletes (the names released, the block given back, then operator delete),
 * the next. The list is deleted before the name is released. */
struct Entry01347f20 { /* derived name */

    ~Entry01347f20()
    {
        delete names;
    }

    u32 hash;                   /* +0x0 */
    Name name;                  /* +0x4 */
    Array01343a80<Name> *names; /* +0x8 */
    Entry01347f20 *next;        /* +0x10 */
};

/* FUN_01347f20: every entry emptied, each list of names deleted */
template void NameTable<Entry01347f20, 256>::clear();

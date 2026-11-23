/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_nametable.h"

/* derived names: an entry of the table of 32 buckets whose destructor
 * FUN_00c1adc0, a static initializer, registers for the global at 0x5937ec8
 * (lea at 0xc1add7; the table's constructor folded to constant data): the hash, the name, 8 bytes not traced, the next. The
 * destructor releases the name only. */
struct Entry013a2360 { /* derived name */
    u32 hash;          /* +0x0 */
    Name name;         /* +0x4 */
    u8 unknown8[0x8];
    Entry013a2360 *next; /* +0x10 */
};

/* FUN_013a2360: with entries left they are emptied, then every block freed */
template NameTable<Entry013a2360, 32>::~NameTable();

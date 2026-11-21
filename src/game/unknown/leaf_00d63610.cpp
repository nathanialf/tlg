/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: a 32-byte entry: a counted reference at +0x0 and a name at
 * +0x8; the rest not traced */
struct Entry00d63610 /* derived name */
{
    Ref00503fb0<Object016b9108> held0; /* +0x0 */
    Name name8;                        /* +0x8 */
    u8 unknownc[0x14];
};

/* derived name: the entry at the index emptied, its name first, then its
 * reference (the calls at 0xd634ba and 0xebd79a) */
void FUN_00d63610(Entry00d63610 *entries, unsigned index)
{
    Entry00d63610 &entry = entries[index];
    entry.name8.release();
    entry.held0.release();
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_entry00c8b0d0.h"

/* derived names: the four 0xb0-byte entries at +0xc0 of the object put
 * back to empty (tlg_game_entry00c8b0d0.h): the float at +0x30 of each set
 * to -1, the reference at +0x98 emptied by compare-and-swap, then the
 * pointer at +0x80 cleared, the int at +0x34 set to -1 and the pointer at
 * +0xa0 cleared. The owner is not traced. */

struct Object00373200 { /* derived name */
    u8 unknown0[0xc0];
    Entry00c8b0d0 entries[4]; /* +0xc0 */
};

// NONMATCHING: CodeGenPrepare's preheader protection (held beside D63, round 202B): 62/67; the base has
// `mov edx, 0xdeadc0de` in the flag's block right after the thread-local's address (0x373285), the build in a
// preheader block of the exchange loop behind the `jne`
void FUN_00373200(Object00373200 *self) /* derived name */
{
    for (int i = 0; i < 4; ++i) {
        Entry00c8b0d0 &entry = self->entries[i];
        entry.unknown30 = -1.0f;
        entry.unknown98.clear();
        entry.unknown80 = 0;
        entry.unknown34 = -1;
        entry.unknowna0 = 0;
    }
}

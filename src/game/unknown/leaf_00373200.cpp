/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the four 0xb0-byte entries at +0xf0 of the object put
 * back to empty: the float at +0x0 set to -1, the counted reference at
 * +0x68 emptied by compare-and-swap, then the pointer at +0x50 cleared, the
 * int at +0x4 set to -1 and the pointer at +0x70 cleared. The owner and the
 * entries' other members are not traced. */
struct Entry00373200 { /* derived name */
    float unknown0;    /* +0x0 */
    int unknown4;      /* +0x4 */
    u8 unknown8[0x48];
    void *unknown50; /* +0x50 */
    u8 unknown58[0x10];
    AtomicRef0045c470<Node00503fb0> unknown68; /* +0x68 */
    void *unknown70;                           /* +0x70 */
    u8 unknown78[0x38];
};

struct Object00373200 { /* derived name */
    u8 unknown0[0xf0];
    Entry00373200 entries[4]; /* +0xf0 */
};

// NONMATCHING: CodeGenPrepare's preheader protection (held beside D63, round 202B): 62/67; the base has
// `mov edx, 0xdeadc0de` in the flag's block right after the thread-local's address (0x373285), the build in a
// preheader block of the exchange loop behind the `jne`
void FUN_00373200(Object00373200 *self) /* derived name */
{
    for (int i = 0; i < 4; ++i) {
        Entry00373200 &entry = self->entries[i];
        entry.unknown0 = -1.0f;
        entry.unknown68.clear();
        entry.unknown50 = 0;
        entry.unknown4 = -1;
        entry.unknown70 = 0;
    }
}

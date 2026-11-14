/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: an object put back to empty: the counted reference at
 * +0x28 emptied by compare-and-swap, the name at +0x30 assigned the empty
 * name (the empty entry's count raised, the old name's dropped, the index
 * cleared twice: 0x2bc10f and 0x2bc11f), the int at +0x34 cleared and the
 * four 8-byte words at +0x40 zeroed (one unaligned 32-byte store). The
 * owner and the words' types are not traced. */
struct Object002bc040 { /* derived name */
    u8 unknown0[0x28];
    AtomicRef0045c470<Node00503fb0> unknown28; /* +0x28 */
    Name name;                                 /* +0x30 */
    int unknown34;                             /* +0x34 */
    u8 unknown38[0x8];
    u64 unknown40[4]; /* +0x40 */
};

void FUN_002bc040(Object002bc040 *self) /* derived name */
{
    self->unknown28.clear();
    self->name = Name();
    self->unknown34 = 0;
    self->unknown40[0] = 0;
    self->unknown40[1] = 0;
    self->unknown40[2] = 0;
    self->unknown40[3] = 0;
}

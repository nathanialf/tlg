/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_math.h"

/* derived names: a 0x50-byte record copied member by member: an int, a
 * counted reference at +0x8 replaced by compare-and-swap, two 16-byte
 * aligned vectors, a Name at +0x30, eight bytes at +0x34 moved as one, and
 * a third vector. The members' types beyond their sizes and alignments are
 * not traced. */
struct Pair006df5e0 { /* derived name */
    int unknown0;
    int unknown4;
};

struct Record006df5e0 { /* derived name */
    void operator=(const Record006df5e0 &other);

    int unknown0;                             /* +0x0 */
    AtomicRef0045c470<Node00503fb0> unknown8; /* +0x8 */
    Float4A unknown10;                        /* +0x10 */
    Float4A unknown20;                        /* +0x20 */
    Name unknown30;                           /* +0x30 */
    Pair006df5e0 unknown34;                   /* +0x34 */
    Float4A unknown40;                        /* +0x40 */
};

void Record006df5e0::operator=(const Record006df5e0 &other)
{
    unknown0 = other.unknown0;
    unknown8 = other.unknown8;
    unknown10 = other.unknown10;
    unknown20 = other.unknown20;
    unknown30 = other.unknown30;
    unknown34 = other.unknown34;
    unknown40 = other.unknown40;
}

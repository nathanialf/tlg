/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_math.h"

/* derived names: a 0x80-byte record copied member by member: a 16-byte
 * aligned vector, two ints, a 64-byte block and a 16-byte one moved
 * unaligned, a pointer between them, and a counted reference at +0x78
 * replaced by compare-and-swap. The members' types beyond their sizes and
 * alignments are not traced. */
struct Block00503860 { /* derived name */
    Float4 rows[4];
};

struct Record00503860 { /* derived name */
    void operator=(const Record00503860 &other);

    Float4A unknown0; /* +0x0 */
    int unknown10;    /* +0x10 */
    int unknown14;    /* +0x14 */
    u8 unknown18[0x8];
    Block00503860 unknown20;                   /* +0x20 */
    void *unknown60;                           /* +0x60 */
    Float4 unknown68;                          /* +0x68 */
    AtomicRef0045c470<Node00503fb0> unknown78; /* +0x78 */
};

void Record00503860::operator=(const Record00503860 &other)
{
    unknown0 = other.unknown0;
    unknown10 = other.unknown10;
    unknown14 = other.unknown14;
    unknown20 = other.unknown20;
    unknown60 = other.unknown60;
    unknown68 = other.unknown68;
    unknown78 = other.unknown78;
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_math.h"

/* derived names: a record copied member by member: the counted reference
 * at +0x0 replaced by compare-and-swap, the name at +0x8 assigned, and the
 * 16 bytes at +0xc moved unaligned. The members' types beyond these are
 * not traced. */
struct Record00d634e0 { /* derived name */
    void operator=(const Record00d634e0 &other);

    AtomicRef0045c470<Node00503fb0> unknown0; /* +0x0 */
    Name unknown8;                            /* +0x8 */
    Float4 unknownc;                          /* +0xc */
};

void Record00d634e0::operator=(const Record00d634e0 &other)
{
    unknown0 = other.unknown0;
    unknown8 = other.unknown8;
    unknownc = other.unknownc;
}

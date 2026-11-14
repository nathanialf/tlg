/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: the copy of a record of an int, an exchanged reference
 * and two names, written member by member in the order of the offsets. The
 * record's class is not traced. */
struct Record006df470 { /* derived name */
    void operator=(const Record006df470 &other);

    int unknown0;                           /* +0x0 */
    AtomicRef0045c470<Node00503fb0> object; /* +0x8 */
    Name unknown10;                         /* +0x10 */
    Name unknown14;                         /* +0x14 */
};

void Record006df470::operator=(const Record006df470 &other)
{
    unknown0 = other.unknown0;
    object = other.object;
    unknown10 = other.unknown10;
    unknown14 = other.unknown14;
}

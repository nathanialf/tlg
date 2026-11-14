/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the copy of a record of an int and two exchanged
 * references, written member by member: the int at +0x0 stored, then the
 * references at +0x8 and +0x10 assigned. The record's class is not traced. */
struct Record00f54b50 { /* derived name */
    void operator=(const Record00f54b50 &other);

    int unknown0;                           /* +0x0 */
    AtomicRef0045c470<Node00503fb0> first;  /* +0x8 */
    AtomicRef0045c470<Node00503fb0> second; /* +0x10 */
};

void Record00f54b50::operator=(const Record00f54b50 &other)
{
    unknown0 = other.unknown0;
    first = other.first;
    second = other.second;
}

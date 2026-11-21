/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: a record FUN_006d9xxx copies from +0x2370 to +0x4f00 of
 * its object (0x6d946d): an int, two counted references another thread may
 * replace and a name. Their meaning is not traced. */
struct Binding006df730 /* derived name */
{
    /* 0x6df730: the members assigned in turn */
    void operator=(const Binding006df730 &other);

    int unknown0;                             /* +0x0 */
    AtomicRef0045c470<Object016b9108> held8;  /* +0x8 */
    AtomicRef0045c470<Object016b9108> held10; /* +0x10 */
    Name name18;                              /* +0x18 */
};

void Binding006df730::operator=(const Binding006df730 &other)
{
    unknown0 = other.unknown0;
    held8 = other.held8;
    held10 = other.held10;
    name18 = other.name18;
}

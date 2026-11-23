/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016aeab0.h"
#include "tlg_game_object01388080.h"

/* derived names: the record at +0x68 of the object the pointer at
 * 0x57c9390 holds, and the object at its +0xc8, as slot 10 reads them */
struct Current00822740 { /* derived name */
    u8 unknown0[0xc4];
    Name name; /* +0xc4 */
};

struct Record00822740 { /* derived name */
    u8 unknown0[0xc8];
    Current00822740 *current; /* +0xc8 */
};

struct Game00822740 { /* derived name */
    u8 unknown0[0x68];
    Record00822740 *unknown68; /* +0x68 */
};

extern Game00822740 *D_57c9390;

// NONMATCHING: the base takes the sine of five times the time at +0x18c of
// 0x5938c40 (`call` of _FSin with 0, 0 at 0x8227ac) before the marks and
// uses no result: the open class of a value computed and not used; not written
// (a discarded sinf() is removed: clang gives the builtin's declaration
// readnone, so the base's kept call went to a function not known pure).
// Without the call the build needs no frame: 0/37 here
void Object016aeab0::slot10(int)
{
    Marked00822740 *first = held238.get();
    if (!first)
        return;
    Marked00822740 *second = held240.get();
    if (!second)
        return;
    Current00822740 *current = D_57c9390->unknown68->current;
    if (!current)
        return;
    if (unknown24c == 0 && !(first->name == current->name) && !(second->name == current->name))
        return;
    held238.get()->flags238 |= 2;
    held240.get()->flags238 |= 2;
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: hands the two objects a source refers to at +0xd8 and
 * +0xe0 to a target's references at the same places; a reference the
 * source does not hold leaves the other's alone. The first argument is not
 * used (the object the function is a member of, by its place). The classes
 * are not traced. */
struct Holder00d87b00; /* derived name */

class Base00d87b00 : public Node00503fb0 /* derived name */
{
};

/* what the source refers to: a class over the target's (`cmp rcx, rbx` at
 * 0xd87b44: the pointer converted where it is exchanged and compared) */
class Value00d87b00 : public Base00d87b00 /* derived name */
{
};

struct Source00d87b00 { /* derived name */
    u8 unknown0[0xd8];
    AtomicRef0045c470<Value00d87b00> first;  /* +0xd8 */
    AtomicRef0045c470<Value00d87b00> second; /* +0xe0 */
};

struct Target00d87b00 { /* derived name */
    u8 unknown0[0xd8];
    AtomicRef0045c470<Base00d87b00> first;  /* +0xd8 */
    AtomicRef0045c470<Base00d87b00> second; /* +0xe0 */
};

void FUN_00d87b00(Holder00d87b00 *, const Source00d87b00 *source,
                  Target00d87b00 *target) /* derived name */
{
    if (source->first.get())
        target->first.set(source->first.get());
    if (source->second.get())
        target->second.set(source->second.get());
}

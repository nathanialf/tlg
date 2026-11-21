/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: slot 3 of the vtable at 0x016c28b8 (its pointer at 0x16c28e0): the
 * two counted references at 0x1868 and 0x1870 of the state reached from the
 * object's owner at +0x70 (its +0x10, then that one's +0x270) emptied by
 * compare-and-swap, then FUN_01256d10 on the owner as a tail call. Classes and
 * fields not traced further. */
struct State01265110 /* derived name */
{
    u8 unknown0[0x1868];
    AtomicRef0045c470<Object016b9108> first;  /* +0x1868 */
    AtomicRef0045c470<Object016b9108> second; /* +0x1870 */
};

struct World01265110 /* derived name */
{
    u8 unknown0[0x270];
    State01265110 *state270; /* +0x270 */
};

struct Owner01265110 /* derived name */
{
    u8 unknown0[0x10];
    World01265110 *world10; /* +0x10 */
};

struct Object01265110 /* derived name */
{
    u8 unknown0[0x70];
    Owner01265110 *owner70; /* +0x70 */
};

void FUN_01256d10(Owner01265110 *owner); /* derived name */

void FUN_01265110(Object01265110 *self) /* derived name */
{
    Owner01265110 *owner = self->owner70;
    owner->world10->state270->first.clear();
    owner->world10->state270->second.clear();
    FUN_01256d10(owner);
}

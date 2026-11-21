/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: slot 3 of the vtable at 0x016c0710 (its pointer at 0x16c0738): the
 * two counted references at 0x1df8 and 0x1e00 of the state reached from the
 * object's owner at +0x70 (its +0x10, then that one's +0x270) emptied by
 * compare-and-swap, then FUN_00fea640 on the owner as a tail call. Classes and
 * fields not traced further. */
struct State00ff8a40 /* derived name */
{
    u8 unknown0[0x1df8];
    AtomicRef0045c470<Object016b9108> first;  /* +0x1df8 */
    AtomicRef0045c470<Object016b9108> second; /* +0x1e00 */
};

struct World00ff8a40 /* derived name */
{
    u8 unknown0[0x270];
    State00ff8a40 *state270; /* +0x270 */
};

struct Owner00ff8a40 /* derived name */
{
    u8 unknown0[0x10];
    World00ff8a40 *world10; /* +0x10 */
};

struct Object00ff8a40 /* derived name */
{
    u8 unknown0[0x70];
    Owner00ff8a40 *owner70; /* +0x70 */
};

void FUN_00fea640(Owner00ff8a40 *owner); /* derived name */

void FUN_00ff8a40(Object00ff8a40 *self) /* derived name */
{
    Owner00ff8a40 *owner = self->owner70;
    owner->world10->state270->first.clear();
    owner->world10->state270->second.clear();
    FUN_00fea640(owner);
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_name.h"
#include "tlg_libc.h"

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x526284): finds the node its argument refers to in the owner's list (from
 * the current index to the end, then from the start), makes it the current
 * one, and when the argument's Name contains "angle" stores the owner's int
 * value in that node's value; returns 0. Handler unknown. */
int FUN_00599700(Owner583950 *self, void *arg) /* derived name */
{
    NamedNode583950 *node = static_cast<NamedNode583950 *>(arg);
    unsigned found;
    if (!self->find(node->target, found))
        return 0;
    self->current = found;
    int *value = reinterpret_cast<int *>(self->currentValue());
    if (value && strstr(D_17ac870[node->name].string0, "angle"))
        *value = self->intValue;
    return 0;
}

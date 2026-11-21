/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_node.h"

/* derived names: a handler whose address FUN_00525530 takes: when the node
 * is in the owner's first list, the counted reference its value holds is
 * dropped and emptied (Ref00503fb0::release); then the node at +0x28 is
 * dispatched. Returns 0. Handler unknown. */
int FUN_0058ddf0(Owner583950 *self, Node583950 *node) /* derived name */
{
    Ref00503fb0<Object016b9108> *reference =
        self->cursor.select(node)
            ? reinterpret_cast<Ref00503fb0<Object016b9108> *>(self->cursor.value())
            : 0;
    if (reference)
        reference->release();
    self->dispatch(node->child);
    return 0;
}

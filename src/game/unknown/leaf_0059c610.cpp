/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: the value FUN_0059c610's node keeps: a pointer at +0x8
 * (not traced further). */
struct Value59c610 /* derived name */
{
    u8 unknown0[8];
    void *unknown8; /* +0x8 */
};

int FUN_0059d280(void *vm, const CallArguments583950 *arguments); /* derived name */

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x525f48): with its argument in the owner's list and a pointer at +0x8
 * of the node's value, dispatches the node at +0x28 through the owner's handler
 * table, then appends FUN_0059d280 with the node and its value to the
 * owner's call frame (as FUN_005995c0 does); the owner's +0xd8 is set to 1
 * on every path (the base's three exits and the full queue's all reach the
 * store at 0x59c6fe); returns 0. Handler unknown. */
int FUN_0059c610(FrameOwner583950 *self, Node583950 *node) /* derived name */
{
    Value59c610 *value =
        self->cursor.select(node) ? reinterpret_cast<Value59c610 *>(self->cursor.value()) : 0;
    if (value && value->unknown8) {
        self->dispatch(node->child);
        const CallArguments583950 arguments = {node, value};
        self->frame->push(FUN_0059d280, arguments);
    }
    self->unknownd8 = 1;
    return 0;
}

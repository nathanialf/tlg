/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: the value FUN_0059c610's node keeps: a pointer at +0x8
 * (not traced further). */
struct Value59c610 /* derived name */
{
    u8 unknown0[8];
    void *unknown8; /* +0x8 */
};

void FUN_0059d280(void *vm); /* derived name */

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x525f48): with its argument in the owner's list and a pointer at +0x8
 * of the node's value, dispatches the node at +0x28 through the owner's handler
 * table, then appends FUN_0059d280 with the node and its value to the
 * owner's call frame (as FUN_005995c0 does), the owner's +0xd8 set to 1
 * when it was appended; returns 0. Handler unknown. */
// NONMATCHING: the queued function's address: FUN_0059d280 is not defined in the game module yet,
// so its address is a GOT load placed before the slot's `shl rsi, 5`; the base's `lea` comes
// after it (every other instruction equal in the module); equal once FUN_0059d280 is written
int FUN_0059c610(FrameOwner583950 *self, Node583950 *node) /* derived name */
{
    Value59c610 *value =
        self->cursor.select(node) ? reinterpret_cast<Value59c610 *>(self->cursor.value()) : 0;
    if (value && value->unknown8) {
        self->dispatch(node->child);
        const CallArguments583950 arguments = {node, value};
        if (self->frame->push(FUN_0059d280, arguments))
            self->unknownd8 = 1;
    }
    return 0;
}

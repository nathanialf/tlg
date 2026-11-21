/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a node with flags at +0x28 and at +0x30 (FUN_0059f910). */
struct FlagsNode59f910 /* derived name */
{
    u8 unknown0[0x28];
    u8 flags; /* +0x28: bit 0 set, nothing is queued */
    u8 unknown29[7];
    u8 flags30; /* +0x30: bit 0 set, the call is queued */
};

int FUN_0059fa50(void *vm, const CallArguments583950 *arguments); /* derived name */

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x525677): in the state 0 or 1 of its argument, appends FUN_0059fa50
 * with the node and its value to the owner's call frame when bit 0 of its
 * flags at +0x28 is clear and bit 0 of those at +0x30 set, then copies the
 * state to the owner's +0xd8 (as FUN_005995c0 does, without starting the
 * state); returns 0. Handler unknown. */
int FUN_0059f910(FrameOwner583950 *self, FlagsNode59f910 *node) /* derived name */
{
    int *value = self->cursor.select(node) ? reinterpret_cast<int *>(self->cursor.value()) : 0;
    u8 *state = self->selectState(node);
    switch (*state) {
    case 0:
    case 1:
        if (!(node->flags & 1) && (node->flags30 & 1)) {
            const CallArguments583950 arguments = {node, value};
            self->frame->push(FUN_0059fa50, arguments);
        }
        self->unknownd8 = *state;
        break;
    }
    return 0;
}

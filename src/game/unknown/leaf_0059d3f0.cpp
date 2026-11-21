/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a node of the kind FUN_0059d3f0 and its four copies are
 * given: the three values handed to FUN_00c0f8b0 */
struct CallNode0059d3f0 { /* derived name */
    u8 unknown0[0x28];
    int unknown28; /* +0x28 */
    u8 unknown2c[4];
    void *unknown30; /* +0x30 */
    int unknown38;   /* +0x38 */
};

int FUN_00c0f8b0(Owner583950 *self, void *, int, int, int, int);  /* derived name */
int FUN_0059d4e0(void *vm, const CallArguments583950 *arguments); /* derived name */

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x52588c): the node made the current one and its state byte read (no
 * check for a node not in the list); a state of 0 becomes 1, and in either
 * state FUN_00c0f8b0 is run with the node's values, a call of FUN_0059d4e0
 * with the node appended to the frame when it answers, and the state left
 * at +0xd8. Returns 0. Handler unknown. */
// NONMATCHING: 73/78, the same size: two instructions in the other order twice: the base
// reads the node's +0x28 before +0x30 and +0x38 (the build in argument order), and forms the
// entry's index (`shl rsi, 5`) before the function's address (`lea rdi`), as 0xc0bc10.
// The four copies (0x5a4a10, 0x5a4d80, 0x5a5aa0, 0x5a6020) are not written.
int FUN_0059d3f0(FrameOwner583950 *self, CallNode0059d3f0 *node) /* derived name */
{
    u8 *state = self->selectState(node);
    switch (*state) {
    case 0:
        *state = 1;
    case 1:
        if (FUN_00c0f8b0(self, node->unknown30, node->unknown38, node->unknown28, 0, 0))
            self->frame->push(FUN_0059d4e0, node);
        self->unknownd8 = *state;
        break;
    }
    return 0;
}

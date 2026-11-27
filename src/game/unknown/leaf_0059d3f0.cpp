/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_mover0059d4e0.h"

/* derived names: a node of the kind FUN_0059d3f0 and its four copies are
 * given: the mode and the children FUN_00c0f8b0 runs */
struct CallNode0059d3f0 { /* derived name */
    u8 unknown0[0x28];
    int mode; /* +0x28 */
    u8 unknown2c[4];
    Node583950 **children; /* +0x30 */
    unsigned count;        /* +0x38 */
};

/* derived names: the body of FUN_0059d3f0 and its four copies, each with its
 * own call: the node made the current one and its state byte read (no
 * check for a node not in the list); a state of 0 becomes 1, and in either
 * state FUN_00c0f8b0 is run with the node's values, the call appended to
 * the frame with the node when it answers, and the state left at +0xd8.
 * Returns 0. */
static inline int runMoverNode(FrameOwner583950 *self, CallNode0059d3f0 *node,
                               CallFunction583950 call) /* derived name */
{
    u8 *state = self->selectState(node);
    switch (*state) {
    case 0:
        *state = 1;
    case 1:
        if (self->runChildren(node->mode, node->children, node->count))
            self->frame->push(call, node);
        self->unknownd8 = *state;
        break;
    }
    return 0;
}

/* derived names: handlers whose addresses FUN_00525530 takes (lea at
 * 0x52588c for FUN_0059d3f0), each queueing its own call of
 * tlg_game_mover0059d4e0.h (leaf_0059d4e0.cpp). The node's mode is read
 * before its children (Owner583950::runChildren); the call's address is a
 * `lea` once the call is defined in the module. Handler unknown. */
int FUN_0059d3f0(FrameOwner583950 *self, CallNode0059d3f0 *node) /* derived name */
{
    return runMoverNode(self, node, FUN_0059d4e0);
}

int FUN_005a4a10(FrameOwner583950 *self, CallNode0059d3f0 *node) /* derived name */
{
    return runMoverNode(self, node, FUN_005a4b00);
}

int FUN_005a4d80(FrameOwner583950 *self, CallNode0059d3f0 *node) /* derived name */
{
    return runMoverNode(self, node, FUN_005a4e70);
}

int FUN_005a5aa0(FrameOwner583950 *self, CallNode0059d3f0 *node) /* derived name */
{
    return runMoverNode(self, node, FUN_005a5b90);
}

int FUN_005a6020(FrameOwner583950 *self, CallNode0059d3f0 *node) /* derived name */
{
    return runMoverNode(self, node, FUN_005a6110);
}

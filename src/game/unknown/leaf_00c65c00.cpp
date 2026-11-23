/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_log.h"
#include "tlg_math.h"

extern const char D_15b2c56[]; /* "FlowAbs(%s) : (in_value => out_value) : %f => %f\n" */

/* derived names: the handler of node kind 17 in the 'XFIT' owners' default
 * table (FlowAbs): each child of the node its argument refers to dispatches
 * the node it holds at +0x38 with the absolute value of the owner's float
 * as the owner's value (type 4), and a message is written when the node
 * asks for one. Returns 0. */
int FUN_00c65c00(ValueOwner583950 *self, void *arg) /* derived name */
{
    ParentNode583950Kind17 *node =
        static_cast<ParentNode583950Kind17 *>(static_cast<NamedNode583950 *>(arg)->target);
    const float in = self->floatValue;
    const float out = fabsf(in);
    Node583950 **end = node->children + node->count;
    for (Node583950 **child = node->children; child != end; ++child) {
        Node583950 *next = *child;
        self->valueType = 4;
        self->floatValue = out;
        self->dispatchHeld(next);
    }
    if (node->debugFlags & 1)
        FUN_00c831d0(self, D_15b2c56, D_17ac870[node->name.index].string0, in, out);
    return 0;
}

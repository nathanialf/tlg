/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_log.h"
#include "tlg_game_name.h"

/* derived names: the node "FlowIndexFilter" (its message's name) that
 * FUN_00595080's argument holds at +0x38: its name at +0xc, bit 0 of +0x28
 * writes the message, the children at +0x30. */
struct FlowIndexFilter /* derived name */
{
    u8 unknown0[0xc];
    Name name; /* +0xc */
    u8 unknown10[0x18];
    unsigned debugFlags; /* +0x28 */
    u8 unknown2c[4];
    Node583950 **children; /* +0x30 */
    unsigned count;        /* +0x38 */
};

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x526183): an int value (type 0) or a float value (type 4) of the owner that
 * is not negative is given back to the owner, with its type, before each
 * child of the filter its argument holds at +0x38 is handed on by the kind
 * of the node it holds at +0x38 (Owner583950::dispatchHeld); then, with bit
 * 0 of the filter's +0x28, the message. Returns 0. The float arm is written
 * first: the switch the chain becomes compares the arm written first last
 * (the base tests 0, then 4). Handler unknown. */
int FUN_00595080(ValueOwner583950 *self, Node583950 *arg) /* derived name */
{
    FlowIndexFilter *node = reinterpret_cast<FlowIndexFilter *>(arg->child38);
    if (self->valueType == 4) {
        const float value = self->floatValue;
        if (value >= 0.0f) {
            Node583950 **end = node->children + node->count;
            for (Node583950 **it = node->children; it != end; ++it) {
                Node583950 *child = *it;
                self->valueType = 4;
                self->floatValue = value;
                self->dispatchHeld(child);
            }
            if (node->debugFlags & 1)
                FUN_00c831d0(0, "FlowIndexFilter(%s) eval, in_value => out, %f => %f\n",
                             D_17ac870[node->name.index].string0, value, value);
        }
    } else if (self->valueType == 0) {
        const int value = self->intValue;
        if (value >= 0) {
            Node583950 **end = node->children + node->count;
            for (Node583950 **it = node->children; it != end; ++it) {
                Node583950 *child = *it;
                self->valueType = 0;
                self->intValue = value;
                self->dispatchHeld(child);
            }
            if (node->debugFlags & 1)
                FUN_00c831d0(0, "FlowIndexFilter(%s) : (eval, in_value => out) : %d => %d\n",
                             D_17ac870[node->name.index].string0, value, value);
        }
    }
    return 0;
}

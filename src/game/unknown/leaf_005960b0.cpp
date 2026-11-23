/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_array.h"
#include "tlg_game_log.h"
#include "tlg_game_name.h"

/* derived names: the node "FlowValueMapIncreaser" (its message's name) that
 * FUN_005960b0's argument holds at +0x38: ranges of the input (a lower and
 * an upper bound each) and the rate the output rises at in each, the
 * output's initial value and its bounds, its children at +0x88. */
struct FlowValueMapIncreaser /* derived name */
{
    u8 unknown0[0xc];
    Name name; /* +0xc */
    u8 unknown10[0x18];
    unsigned flags; /* +0x28: bit 0 the input passes through, bit 1 writes the message */
    u8 unknown2c[4];
    Array05943280<float> lower; /* +0x30 */
    Array05943280<float> upper; /* +0x48 */
    Array05943280<float> rates; /* +0x60 */
    float initialValue;         /* +0x78 */
    float minimum;              /* +0x7c */
    float maximum;              /* +0x80 */
    u8 unknown84[4];
    Array05943280<Node583950 *> children; /* +0x88 */
};

template <class T> static inline T minimum(T a, T b)
{
    return a < b ? a : b;
}

/* the value kept within the bounds (derived name) */
template <class T> static inline const T &clamp(const T &value, const T &low, const T &high)
{
    return value < low ? low : value < high ? value : high;
}

/* derived names: a handler whose address FUN_00525530 takes: the output the
 * owner's list keeps for the node (its initial value on the first call)
 * rises, while the owner's float value lies in one of the node's ranges (the
 * first closed below, the others open), by that range's rate over the
 * owner's time step, kept within its bounds; with bit 0 of the node's +0x28
 * the output is the input itself. The output is given to the owner as a
 * float (type 4) before each child of the node is handed on by the kind of
 * the node it holds at +0x38 (Owner583950::dispatchHeld); then, with bit 1,
 * the message. Returns 0. Handler unknown. */
// NONMATCHING: the range search's counter: the base raises it in each arm of the first-range
// test before the bound compares (`mov edi, 1` where i is 0, `inc edi` elsewhere; FUN_00595c80's
// class), the build once in the latch; and self and the output in r12 and r13 swapped
int FUN_005960b0(ValueOwner583950 *self, Node583950 *arg) /* derived name */
{
    FlowValueMapIncreaser *node = reinterpret_cast<FlowValueMapIncreaser *>(arg->child38);
    float *record = self->cursor.select(node) ? reinterpret_cast<float *>(self->cursor.value()) : 0;
    u8 *state = self->selectState(node);
    switch (*state) {
    case 0:
        *record = node->initialValue;
        *state = 1;
    case 1:
        break;
    default:
        return 0;
    }

    const unsigned count =
        minimum(minimum(node->lower.size(), node->upper.size()), node->rates.size());
    const float value = self->floatValue;
    float out = *record;
    if (node->flags & 1) {
        out = value;
    } else {
        for (unsigned i = 0; i < count; ++i) {
            const float lower = node->lower.at(i);
            const float upper = node->upper.at(i);
            if ((i == 0 ? lower <= value : lower < value) && value <= upper) {
                out = node->rates.at(i) * self->timeStep + out;
                out = clamp(out, node->minimum, node->maximum);
                *record = out;
                break;
            }
        }
    }
    Node583950 *const *end = node->children.end();
    for (Node583950 *const *it = node->children.begin(); it != end; ++it) {
        Node583950 *child = *it;
        self->valueType = 4;
        self->floatValue = out;
        self->dispatchHeld(child);
    }
    if (node->flags & 2)
        FUN_00c831d0(0, "FlowValueMapIncreaser(%s) : (in_value => out_value) : %f => %f\n",
                     D_17ac870[node->name.index].string0, value, out);
    return 0;
}

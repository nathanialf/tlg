/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_array.h"
#include "tlg_game_log.h"
#include "tlg_game_name.h"
#include "tlg_libc.h"

/* derived names: the node "FlowMagnitudeFilter" (its message's name) that
 * FUN_00595510's argument holds at +0x38: ranges of the value's magnitude
 * (a lower and an upper bound each) and the magnitude each range maps to,
 * its children at +0x78. */
struct FlowMagnitudeFilter /* derived name */
{
    u8 unknown0[0xc];
    Name name; /* +0xc */
    u8 unknown10[0x18];
    unsigned debugFlags; /* +0x28: bit 0 writes the message */
    u8 unknown2c[4];
    Array05943280<float> lower;           /* +0x30 */
    Array05943280<float> upper;           /* +0x48 */
    Array05943280<float> values;          /* +0x60 */
    Array05943280<Node583950 *> children; /* +0x78 */
};

template <class T> static inline T minimum(T a, T b)
{
    return a < b ? a : b;
}

/* derived names: a handler whose address FUN_00525530 takes: the owner's
 * value (an int, a float or a vector by its length) is mapped through the
 * filter its argument holds at +0x38: the first range holding it (the first
 * range closed below, the others open) gives the value of that range (a
 * vector keeps its direction and takes that length), else the value is
 * kept; the result is given back to the owner in its type before each
 * child of the filter is handed on by the kind of the node it holds at
 * +0x38 (Owner583950::dispatchHeld); then, with bit 0 of the filter's +0x28,
 * the message. Returns 0. Handler unknown. */
// NONMATCHING: 13/279 in the module: the value type's tests, 0 then 7 then 4 in the
// base, 7 then 4 in the build (FUN_0058fc10's class); then the three searches' counters raised
// in each arm of the first-range test (the class of FUN_00595c80 and FUN_005960b0)
int FUN_00595510(ValueOwner583950 *self, Node583950 *arg) /* derived name */
{
    FlowMagnitudeFilter *node = reinterpret_cast<FlowMagnitudeFilter *>(arg->child38);
    const unsigned count =
        minimum(minimum(node->lower.size(), node->upper.size()), node->values.size());
    switch (self->valueType) {
    case 0: {
        const int in = self->intValue;
        int out = in;
        for (unsigned i = 0; i < count; ++i) {
            const int lower = (int)node->lower.at(i);
            const int upper = (int)node->upper.at(i);
            if ((i == 0 ? lower <= in : lower < in) && in <= upper) {
                out = (int)node->values.at(i);
                break;
            }
        }
        Node583950 *const *end = node->children.end();
        for (Node583950 *const *it = node->children.begin(); it != end; ++it) {
            Node583950 *child = *it;
            self->valueType = 0;
            self->intValue = out;
            self->dispatchHeld(child);
        }
        if (node->debugFlags & 1)
            FUN_00c831d0(0, "FlowMagnitudeFilter(%s) : (in_value_i => out) : %d => %d\n",
                         D_17ac870[node->name.index].string0, in, out);
        break;
    }
    case 7: {
        Float4A out = self->vector;
        if (count) {
            const float lengthSquared = out.x * out.x + out.y * out.y + out.z * out.z;
            const float length = sqrtf(lengthSquared);
            for (unsigned i = 0; i < count; ++i) {
                const float lower = node->lower.at(i);
                const float upper = node->upper.at(i);
                if ((i == 0 ? lower <= length : lower < length) && length <= upper) {
                    const float scale = lengthSquared - 1e-10f > 0.0f ? 1.0f / length : 0.0f;
                    const float value = node->values.at(i);
                    out.x = scale * out.x * value;
                    out.y = scale * out.y * value;
                    out.z = scale * out.z * value;
                    break;
                }
            }
        }
        Node583950 *const *end = node->children.end();
        for (Node583950 *const *it = node->children.begin(); it != end; ++it) {
            Node583950 *child = *it;
            self->valueType = 7;
            self->vector = out;
            self->dispatchHeld(child);
        }
        if (node->debugFlags & 1)
            FUN_00c831d0(0, "FlowMagnitudeFilter(%s) : ", D_17ac870[node->name.index].string0);
        break;
    }
    case 4: {
        const float in = self->floatValue;
        float out = in;
        for (unsigned i = 0; i < count; ++i) {
            const float lower = node->lower.at(i);
            const float upper = node->upper.at(i);
            if ((i == 0 ? lower <= in : lower < in) && in <= upper) {
                out = node->values.at(i);
                break;
            }
        }
        Node583950 *const *end = node->children.end();
        for (Node583950 *const *it = node->children.begin(); it != end; ++it) {
            Node583950 *child = *it;
            self->valueType = 4;
            self->floatValue = out;
            self->dispatchHeld(child);
        }
        if (node->debugFlags & 1)
            FUN_00c831d0(0, "FlowMagnitudeFilter(%s) : (in_value_f => out) : %f => %f\n",
                         D_17ac870[node->name.index].string0, in, out);
        break;
    }
    }
    return 0;
}

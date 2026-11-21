/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_array.h"
#include "tlg_game_log.h"
#include "tlg_game_name.h"

/* derived names: the node "FlowValueFilter" (its message's name) that
 * FUN_00595c80's argument holds at +0x38: ranges of the value (a lower and
 * an upper bound each) and the value each range maps to, its children at
 * +0x78. */
struct FlowValueFilter /* derived name */
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

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x52616c): the owner's float value is mapped through the filter its
 * argument holds at +0x38: the first range holding it (the first range
 * closed below, the others open) gives the value of that range, else the
 * value is kept; the result is given back to the owner as a float (type 4)
 * before each child of the filter is handed on by the kind of the node it
 * holds at +0x38 (Owner583950::dispatchHeld); then, with bit 0 of the
 * filter's +0x28, the message (its format says %d of the two floats it is
 * given). Returns 0. Handler unknown. */
// NONMATCHING: the search's counter: the base raises it before the bound tests (`mov esi, 1` on
// the first range's arm, `inc esi` on the others'), the build at the loop's end; everything
// before the loop and the children's loop equal
int FUN_00595c80(ValueOwner583950 *self, Node583950 *arg) /* derived name */
{
    FlowValueFilter *node = reinterpret_cast<FlowValueFilter *>(arg->child38);
    const float value = self->floatValue;
    float out = value;
    const unsigned count =
        minimum(minimum(node->lower.size(), node->upper.size()), node->values.size());
    for (unsigned i = 0; i < count; ++i) {
        const float lower = node->lower.at(i);
        const float upper = node->upper.at(i);
        if ((i == 0 ? lower <= value : lower < value) && value <= upper) {
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
        FUN_00c831d0(0, "FlowValueFilter(%s) : (in_value_f => out) : %d => %d\n",
                     D_17ac870[node->name.index].string0, value, out);
    return 0;
}

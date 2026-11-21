/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_array.h"
#include "tlg_game_log.h"
#include "tlg_game_name.h"

/* derived names: the node "FlowValueMapper" (its message's name) that
 * FUN_00596650's argument holds at +0x38: an input range mapped onto an
 * output range, its children at +0x40. */
struct FlowValueMapper /* derived name */
{
    u8 unknown0[0xc];
    Name name; /* +0xc */
    u8 unknown10[0x18];
    unsigned debugFlags; /* +0x28: bit 0 writes the message */
    float inMinimum;     /* +0x2c */
    float inMaximum;     /* +0x30 */
    float outMinimum;    /* +0x34 */
    float outMaximum;    /* +0x38 */
    u8 unknown3c[4];
    Array05943280<Node583950 *> children; /* +0x40 */
};

template <class T> static inline T minimum(T a, T b)
{
    return a < b ? a : b;
}

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x526173): the owner's float value is placed in the mapper's input range
 * (1 for an empty range), clamped to 0 to 1 and carried onto its output
 * range; the result is given back to the owner as a float (type 4) before
 * each child of the mapper is handed on by the kind of the node it holds at
 * +0x38 (Owner583950::dispatchHeld); then, with bit 0 of the mapper's +0x28,
 * the message. Returns 0. Handler unknown. */
// NONMATCHING: the clamp: the base selects after the two arms of the ratio meet (`vminss` and
// `vcmpltss; vandnps` on the merged value, 1.0 included); the build threads the 1.0 arm past the
// test and branches on the division's result (`vucomiss; jb`); the rest equal (the message's
// first argument aside, undef in the module)
int FUN_00596650(ValueOwner583950 *self, Node583950 *arg) /* derived name */
{
    FlowValueMapper *node = reinterpret_cast<FlowValueMapper *>(arg->child38);
    const float value = self->floatValue;
    const float range = node->inMaximum - node->inMinimum;
    const float t = range != 0.0f ? (value - node->inMinimum) / range : 1.0f;
    const float clamped = t < 0.0f ? 0.0f : minimum(t, 1.0f);
    const float out = node->outMinimum + (node->outMaximum - node->outMinimum) * clamped;
    Node583950 *const *end = node->children.end();
    for (Node583950 *const *it = node->children.begin(); it != end; ++it) {
        Node583950 *child = *it;
        self->valueType = 4;
        self->floatValue = out;
        self->dispatchHeld(child);
    }
    if (node->debugFlags & 1)
        FUN_00c831d0(0, "FlowValueMapper(%s) : (in_value => out_value) : %f => %f\n",
                     D_17ac870[node->name.index].string0, value, out);
    return 0;
}

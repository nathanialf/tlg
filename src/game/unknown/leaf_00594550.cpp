/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_log.h"
#include "tlg_game_name.h"
#include "tlg_libc.h"

/* derived names: the node "FlowCyclicEase" (its message's name) that
 * FUN_00594550's argument holds at +0x38: the value eased towards where it
 * goes over a duration along a cubic curve through (0, 0), the two control
 * points and (1, 1), the shorter way round a cycle from the minimum to the
 * maximum; a jump larger than the threshold starts a new ease. */
struct FlowCyclicEase /* derived name */
{
    u8 unknown0[0xc];
    Name name; /* +0xc */
    u8 unknown10[0x18];
    unsigned debugFlags; /* +0x28: bit 0 writes the message */
    float minimum;       /* +0x2c */
    float maximum;       /* +0x30 */
    float duration;      /* +0x34 */
    float threshold;     /* +0x38 */
    u8 unknown3c[4];
    float control[4];      /* +0x40: the two control points, x and y of each */
    Node583950 **children; /* +0x50 */
    unsigned count;        /* +0x58 */
};

/* derived names: what a FlowCyclicEase keeps in the owner's list: the eased
 * value, where the ease starts and where it goes, the way it goes (signed)
 * and the time into it. */
struct CyclicEaseValue /* derived name */
{
    u8 unknown0[4];
    float value;  /* +0x4 */
    float source; /* +0x8 */
    float target; /* +0xc */
    float delta;  /* +0x10 */
    float time;   /* +0x14 */
};

static inline float magnitude(float x) /* derived name */
{
    return x > 0.0f ? x : -x;
}

static inline float easeCurve(float t, float first, float second) /* derived name */
{
    const float s = 1.0f - t;
    const float t2 = t * t;
    return t2 * t + (t2 * second + s * (t * first)) * (s * 3.0f);
}

/* derived names: a handler whose address FUN_00525530 takes: the owner's
 * float value is the target of the node's ease (the first call starts at it
 * with the whole duration gone); a target further than the threshold from
 * the last starts a new ease from the eased value, the shorter way round
 * the cycle. The eased value is given to the owner as a float (type 4)
 * before each child of the node is handed on by the kind of the node it
 * holds at +0x38 (Owner583950::dispatchHeld); with bit 0 of +0x28 the
 * message comes first. Returns 0. Handler unknown. */
// NONMATCHING: 193/240 in the module, the same size: the input in xmm7 where the base
// keeps it in xmm0, and in the jump's arm the comparison of the eased value with the input
// scheduled after the stores (the base) or before the target's store (the build); the base
// copies the input into the target's register in that arm, the build copies the target in the
// other
int FUN_00594550(ValueOwner583950 *self, Node583950 *arg) /* derived name */
{
    FlowCyclicEase *node = reinterpret_cast<FlowCyclicEase *>(arg->child38);
    CyclicEaseValue *ease =
        self->cursor.select(node) ? reinterpret_cast<CyclicEaseValue *>(self->currentValue()) : 0;
    u8 *state = self->selectState(node);
    const float in = self->floatValue;
    switch (*state) {
    case 0:
        ease->source = in;
        ease->target = in;
        ease->delta = 0.0f;
        ease->time = node->duration;
        *state = 1;
        break;
    case 1:
        break;
    default:
        return 0;
    }
    float target = ease->target;
    const float range = magnitude(node->maximum - node->minimum);
    float time;
    if (magnitude(target - in) > node->threshold) {
        const float value = ease->value;
        ease->source = value;
        ease->target = target = in;
        const float distance = magnitude(in - value);
        const float way = distance < magnitude(distance - range) ? distance : distance - range;
        ease->delta = value < in ? way : -way;
        ease->time = time = 0.0f;
    } else {
        time = ease->time;
    }
    const float duration = node->duration;
    time += self->timeStep;
    time = time < 0.0f ? 0.0f : (time < duration ? time : duration);
    float u = 1.0f;
    if (duration > 1e-5f) {
        u = time / duration;
        u = u < 0.0f ? 0.0f : (u < 1.0f ? u : 1.0f);
    }
    const float x = easeCurve(u, node->control[0], node->control[2]);
    const float y = easeCurve(x, node->control[1], node->control[3]);
    const float source = ease->source;
    const float step = y * ease->delta;
    const float eased = step + source;
    const float fromMinimum = eased - node->minimum;
    const float wrapped = fmodf(fromMinimum + range, range);
    const float out = wrapped + node->minimum;
    ease->value = out;
    ease->time = time;
    if (node->debugFlags & 1)
        FUN_00c831d0(0,
                     "FlowCyclicEase(%s) : source = %f, target = %f, value0 = %f, value1 = %f, "
                     "value2 = %f, value3 = %f, outValue = %f\n",
                     D_17ac870[node->name.index].string0, source, target, step, eased, fromMinimum,
                     wrapped, out);
    Node583950 **end = node->children + node->count;
    for (Node583950 **child = node->children; child != end; ++child) {
        Node583950 *next = *child;
        self->valueType = 4;
        self->floatValue = out;
        self->dispatchHeld(next);
    }
    return 0;
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_log.h"

extern const char
    D_15b2c88[]; /* "FlowEase(%s) : (in_value, time/duration, source, target => out_value) : ..." */

/* derived name: a cubic curve from 0 to 1 through two control values */
static inline float easeCurve(float t, float first, float second)
{
    const float t2 = t * t;
    return t2 * t + (t2 * second + (1.0f - t) * t * first) * ((1.0f - t) * 3.0f);
}

/* derived names: the handler of node kind 18 in the 'XFIT' owners' default
 * table (FlowEase): the node's value in the owner's list eases from where
 * it was to the owner's float over the node's duration; a first visit
 * starts at the end of an ease (from the initial value when the node says
 * so), and a jump larger than the threshold starts a new one from the
 * current value. Each child of the node then dispatches the node it holds
 * at +0x38 with the eased value as the owner's value (type 4), and a
 * message is written when the node asks for one. Returns 0. */
// NONMATCHING: the message's loads are not folded into vcvtss2sd (the base zeroes xmm4 and
// converts each from memory) and the nops before the loops; the curves' registers are the base's
// with 1 - t written where it is used, after t * t * second (round 507D: greedy assigns the
// block's ranges in order, so u * u and its cube take xmm3 and xmm4 first and 1 - u xmm6)
// Round 578E: equal under cvtzero-01 (not installed: tools/patches/proposed/
// llvm-3.7.1-cvtzero-01-extload-cvtss2sd-zero-passthrough.patch): the base's pass-through is
// a zero of the block made at selection.
int FUN_00c65ce0(ValueOwner583950 *self, void *arg) /* derived name */
{
    ParentNode583950Kind18 *node =
        static_cast<ParentNode583950Kind18 *>(static_cast<NamedNode583950 *>(arg)->target);
    EaseValue583950 *ease =
        self->cursor.select(node) ? reinterpret_cast<EaseValue583950 *>(self->currentValue()) : 0;
    u8 *state = self->selectState(node);
    float in = self->floatValue;
    switch (*state) {
    case 0:
        if (node->flags & 1)
            in = node->initialValue;
        ease->time = node->duration;
        ease->target = in;
        ease->source = in;
        *state = 1;
        break;
    case 1:
        break;
    default:
        return 0;
    }
    float target = ease->target;
    float time;
    const float distance = in - target;
    if ((distance > 0.0f ? distance : -distance) > node->threshold) {
        ease->time = time = 0.0f;
        ease->target = target = in;
        ease->source = ease->value;
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
    const float out = ease->source + (target - ease->source) * y;
    ease->value = out;
    ease->time = time;
    Node583950 **end = node->children + node->count;
    for (Node583950 **child = node->children; child != end; ++child) {
        Node583950 *next = *child;
        self->valueType = 4;
        self->floatValue = out;
        self->dispatchHeld(next);
    }
    if (node->debugFlags & 1)
        FUN_00c831d0(self, D_15b2c88, D_17ac870[node->name.index].string0, in, ease->time,
                     node->duration, ease->source, ease->target, out);
    return 0;
}

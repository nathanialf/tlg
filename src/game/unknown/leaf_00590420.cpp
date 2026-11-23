/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: the node FUN_00590420 is given: bit 0 of +0x28 makes the
 * first visit start from the initial value at +0x2c, the stiffness at
 * +0x30, the children at +0x38 */
struct SpringNode590420 { /* derived name */
    u8 unknown0[0x28];
    unsigned flags;     /* +0x28 */
    float initialValue; /* +0x2c */
    float stiffness;    /* +0x30 */
    u8 unknown34[4];
    Node583950 **children; /* +0x38 */
    unsigned count;        /* +0x40 */
};

/* derived names: the value such a node keeps in the owner's list */
struct SpringValue590420 { /* derived name */
    float position;
    float target;    /* +0x4 */
    float velocity;  /* +0x8 */
    float stiffness; /* +0xc: the node's, taken on the first visit */
};

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x526231): the node's value in the owner's list follows the owner's float
 * as a critically damped spring, one step of the owner's time at a time (a
 * first visit starts at rest, from the initial value when the node says
 * so); each child of the node then dispatches the node it holds at +0x38
 * with the position as the owner's value (type 4). Returns 0. */
// NONMATCHING: 138/140: the product's operands in the other order (`vmulss xmm0, xmm0, xmm4`
// where the base has `vmulss xmm0, xmm4, xmm0`: Reassociate makes stiffness * (in - position)
// part of the tree and puts the shared stiffness * step last; the base keeps that product a
// leaf, ranked with it)
int FUN_00590420(ValueOwner583950 *self, void *arg) /* derived name */
{
    SpringNode590420 *node =
        static_cast<SpringNode590420 *>(static_cast<NamedNode583950 *>(arg)->target);
    SpringValue590420 *spring =
        self->cursor.select(node) ? reinterpret_cast<SpringValue590420 *>(self->currentValue()) : 0;
    u8 *state = self->selectState(node);
    float in = self->floatValue;
    switch (*state) {
    case 0:
        if (node->flags & 1)
            in = node->initialValue;
        spring->position = in;
        spring->target = in;
        spring->stiffness = node->stiffness;
        *state = 1;
        break;
    case 1:
        break;
    default:
        return 0;
    }
    spring->target = in;
    const float position = spring->position;
    const float step = self->timeStep;
    const float stiffness = spring->stiffness;
    const float kt = stiffness * step;
    const float damping = kt + 1.0f;
    spring->velocity =
        (spring->velocity + kt * (stiffness * (in - position))) / (damping * damping);
    const float out = spring->velocity * step + position;
    spring->position = out;
    Node583950 **end = node->children + node->count;
    for (Node583950 **child = node->children; child != end; ++child) {
        Node583950 *next = *child;
        self->valueType = 4;
        self->floatValue = out;
        self->dispatchHeld(next);
    }
    return 0;
}

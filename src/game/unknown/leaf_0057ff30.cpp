/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: the event at the head of the list FUN_0057ff30 reads:
 * its kind at +0x28 and a float at +0x2c */
struct Event0057ff30 { /* derived name */
    u8 unknown0[0x28];
    int kind;        /* +0x28 */
    float unknown2c; /* +0x2c */
};

/* derived names: the object the owner's +0x1b0 holds at +0x380: a list of
 * events at +0xa8 */
struct Events0057ff30 { /* derived name */
    u8 unknown0[0xa8];
    Array05943280<Event0057ff30 *> events; /* +0xa8 */
};

struct Holder0057ff30 { /* derived name */
    u8 unknown0[0x380];
    Events0057ff30 *events; /* +0x380 */
};

/* derived names: the node FUN_0057ff30 is given: the node it walks at
 * +0x28 and a float at +0x30 */
struct Node0057ff30 { /* derived name */
    u8 unknown0[0x28];
    Node583950 *child; /* +0x28 */
    float unknown30;   /* +0x30 */
};

/* derived names: what such a node keeps in the owner's first list: whether
 * the head event is of kind 0x23, the time since it became so and a float */
struct Value0057ff30 { /* derived name */
    int matched;
    float time;     /* +0x4 */
    float unknown8; /* +0x8 */
};

int FUN_00580360(void *vm, const CallArguments583950 *arguments); /* derived name */

/* derived names: a handler: a node with a child found in the owner's list
 * starts in the state 0 (the state 1, the child's state cleared, its value
 * zeroed), dispatches the child in the states 0 to 2 and takes the owner's
 * +0xd8 as its state; then its value follows the head event of the
 * holder's list: when the event becomes of kind 0x23 the time restarts and
 * the event's float (the node's +0x30 where that is negative) is kept; the
 * time advances by the owner's step and FUN_00580360 is queued with the
 * node and its value. Returns 0. Handler unknown. */
// NONMATCHING: 135/182 in a module of its own, 625 bytes against 621: FUN_00580360 is not written, so its address goes through the GOT (`lea rdi, [rip+...]` in the base); the value's reset stores the dword at +8 before the qword at +0 (the base the qword first), and the two tests of the head event are made in the other order (the base branches on the kind's compare first, then on the old flag loaded into ecx)
int FUN_0057ff30(FrameOwner583950 *self, Node0057ff30 *node) /* derived name */
{
    Node583950 *child = node->child;
    if (!child)
        return 0;
    Value0057ff30 *value =
        self->cursor.select(node) ? reinterpret_cast<Value0057ff30 *>(self->cursor.value()) : 0;
    u8 *state = self->selectState(node);
    switch (*state) {
    case 0:
        *state = 1;
        self->clearState(child);
        memset(value, 0, sizeof(*value));
    case 1:
    case 2:
        self->dispatch(child);
        *state = self->unknownd8;
        break;
    }
    Events0057ff30 *events = static_cast<Holder0057ff30 *>(self->unknown1b0)->events;
    Event0057ff30 *event;
    if (events && events->events.size() && (event = events->events[0])) {
        const bool started = event->kind == 0x23;
        const int was = value->matched;
        value->matched = started;
        if (!was && started) {
            const float given = event->unknown2c;
            value->time = 0;
            value->unknown8 = given < 0 ? node->unknown30 : given;
        }
    } else {
        value->matched = 0;
    }
    value->time += self->timeStep;
    CallArguments583950 arguments = {node, value};
    self->frame->push(FUN_00580360, arguments);
    return 0;
}

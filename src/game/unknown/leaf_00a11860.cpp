/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the handlers FUN_00a104a0 stores after their names' hashes
 * (`lea rax, [rip + ...]; mov [rip + ...], rax` from 0xa10685 on). The event
 * names the node at +0x10 and passes the name at +0x14 on. */
struct Event00a104a0 { /* derived name */
    u8 unknown0[0x10];
    Name unknown10; /* +0x10: the node the event is about */
    Name unknown14; /* +0x14 */
};

extern Type00503fb0 *D_5939080; /* derived name: the node's type */

/* derived name: the node (null when the name names none this thread may use
 * of the node's type), the event's second name and two small ints; not
 * traced */
void FUN_00a11900(Object016b85e0 *node, const Name *name, int, int);

void FUN_00a11860(Event00a104a0 *event) /* derived name */
{
    FUN_00a11900(findNamed<Object016b85e0>(event->unknown10, D_5939080), &event->unknown14, 1, 0);
}

// NONMATCHING: register assignment only (42 of 50): the base gives the type r14 and the event
// r15 here (the other way in FUN_00a11860, FUN_00a11f90, FUN_00a12040, whose bodies differ only
// in the two constants); the build gives this one the others' assignment.
// Round 552C, module dumps of this one and FUN_00a11860: the two machine functions are the same
// instructions, differing only in vreg numbers (one fewer: the shared constant) and the last
// block's slots; both allocate the same way. The base's split by equal constants comes from an
// eviction cascade the bytes do not show.
void FUN_00a11ee0(Event00a104a0 *event) /* derived name */
{
    FUN_00a11900(findNamed<Object016b85e0>(event->unknown10, D_5939080), &event->unknown14, 1, 1);
}

void FUN_00a11f90(Event00a104a0 *event) /* derived name */
{
    FUN_00a11900(findNamed<Object016b85e0>(event->unknown10, D_5939080), &event->unknown14, 1, 2);
}

void FUN_00a12040(Event00a104a0 *event) /* derived name */
{
    FUN_00a11900(findNamed<Object016b85e0>(event->unknown10, D_5939080), &event->unknown14, 2, 0);
}

// NONMATCHING: register assignment only (42 of 50): the base gives the type r14 and the event
// r15 here (the other way in FUN_00a11860, FUN_00a11f90, FUN_00a12040, whose bodies differ only
// in the two constants); the build gives this one the others' assignment.
void FUN_00a120e0(Event00a104a0 *event) /* derived name */
{
    FUN_00a11900(findNamed<Object016b85e0>(event->unknown10, D_5939080), &event->unknown14, 0, 0);
}

/* derived name: the node's child at a signed index (`movsxd` under the
 * unsigned counter at 0xa12220) */
static inline Object016b85e0 *childAt(const Object016b85e0 *node, int index)
{
    return node->children[index].get();
}

/* derived names: on the node the event names, sets flag 4 at +0x24 of the
 * child whose name at +0x210 is the event's second name, or of every child
 * when that name is empty */
void FUN_00a12180(Event00a104a0 *event) /* derived name */
{
    Object016b85e0 *node = findNamed<Object016b85e0>(event->unknown10, D_5939080);
    if (!node)
        return;
    unsigned count = node->childCount;
    if (count == 0)
        return;
    if (!event->unknown14.index) {
        for (unsigned i = 0; i < count; ++i)
            childAt(node, i)->unknown24 |= 4;
    } else {
        for (unsigned i = 0; i < count; ++i) {
            Object016b85e0 *child = childAt(node, i);
            if (child->name210 == event->unknown14) {
                child->unknown24 |= 4;
                break;
            }
        }
    }
}

/* derived names: the same, clearing the flag */
void FUN_00a12270(Event00a104a0 *event) /* derived name */
{
    Object016b85e0 *node = findNamed<Object016b85e0>(event->unknown10, D_5939080);
    if (!node)
        return;
    unsigned count = node->childCount;
    if (count == 0)
        return;
    if (!event->unknown14.index) {
        for (unsigned i = 0; i < count; ++i)
            childAt(node, i)->unknown24 &= ~4;
    } else {
        for (unsigned i = 0; i < count; ++i) {
            Object016b85e0 *child = childAt(node, i);
            if (child->name210 == event->unknown14) {
                child->unknown24 &= ~4;
                break;
            }
        }
    }
}

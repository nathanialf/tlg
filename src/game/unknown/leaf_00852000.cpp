/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: four handlers of the table FUN_008506c0 builds (each with
 * its Name: the `lea` at 0x850fb9, 0x851027, 0x85105e, 0x8510cc, stored at
 * 0x581d3f8 and on). Given a context (only tested), an event whose Name at
 * +0x10 names an object of the type D_59391e0 points to, and two more
 * arguments: when the object is there and usable by this thread, its node's
 * Name (+0x210 of the object at +0x28) picks a state among the Names below,
 * and the object the Name at 0x581d1dc names (of the type D_581d718 points
 * to) is given that input with the flag and the first object
 * (FUN_0085dd70); then FUN_00852180 gets the flag, the event, the two
 * arguments and the state, and the handler returns 1. The classes are not
 * traced. */
struct Event00852000 { /* derived name */
    u8 unknown0[0x10];
    Name name; /* +0x10 */
};

struct Node00852000 { /* derived name */
    u8 unknown0[0x210];
    Name name210; /* +0x210 */
};

struct Named00852000 : Object016b9108 /* derived name */
{
    u8 unknown24[0x4];
    Node00852000 *node; /* +0x28 */
};

struct Object0085dd70 : Object016b9108 /* derived name: leaf_0085dd70.cpp's */
{};

void FUN_0085dd70(Object0085dd70 *self, int input, int flag, void *target); /* derived name */
void FUN_00852180(int flag, const Event00852000 *event, void *a, void *b,
                  int state); /* derived name */

extern const Type00503fb0 *D_59391e0; /* derived name: the event object's type */
extern Name D_581d1dc;                /* derived name */
extern const Type00503fb0 *D_581d718; /* derived name: the named object's type */
extern Name D_581d66c;                /* derived name */
extern Name D_581d670;                /* derived name */
extern Name D_581d674;                /* derived name */
extern Name D_581d678;                /* derived name */
extern Name D_581d67c;                /* derived name */

/* the state from the first pair of Names: 0, 1, else 3 */
static int pairState(const Name &name) /* derived name */
{
    if (name == D_581d66c)
        return 0;
    if (name == D_581d670)
        return 1;
    return 3;
}

/* the state from the second set: 4, 5, 6, else 7 */
static int setState(const Name &name) /* derived name */
{
    if (name == D_581d674)
        return 4;
    if (name == D_581d678)
        return 5;
    if (name == D_581d67c)
        return 6;
    return 7;
}

int FUN_00852000(void *context, const Event00852000 *event, void *a, void *b) /* derived name */
{
    int state = 0;
    if (context) {
        Named00852000 *named = findNamed<Named00852000>(event->name, D_59391e0);
        if (named) {
            state = pairState(named->node->name210);
            Object0085dd70 *target = findNamed<Object0085dd70>(D_581d1dc, D_581d718);
            if (target)
                FUN_0085dd70(target, state, 1, named);
        }
    }
    FUN_00852180(1, event, a, b, state);
    return 1;
}

int FUN_00852c50(void *context, const Event00852000 *event, void *a, void *b) /* derived name */
{
    int state = 0;
    if (context) {
        Named00852000 *named = findNamed<Named00852000>(event->name, D_59391e0);
        if (named) {
            state = pairState(named->node->name210);
            Object0085dd70 *target = findNamed<Object0085dd70>(D_581d1dc, D_581d718);
            if (target)
                FUN_0085dd70(target, state, 0, named);
        }
    }
    FUN_00852180(0, event, a, b, state);
    return 1;
}

int FUN_00852dd0(void *context, const Event00852000 *event, void *a, void *b) /* derived name */
{
    int state = 4;
    if (context) {
        Named00852000 *named = findNamed<Named00852000>(event->name, D_59391e0);
        if (named) {
            state = setState(named->node->name210);
            Object0085dd70 *target = findNamed<Object0085dd70>(D_581d1dc, D_581d718);
            if (target)
                FUN_0085dd70(target, state, 1, named);
        }
    }
    FUN_00852180(1, event, a, b, state);
    return 1;
}

int FUN_00852f70(void *context, const Event00852000 *event, void *a, void *b) /* derived name */
{
    int state = 4;
    if (context) {
        Named00852000 *named = findNamed<Named00852000>(event->name, D_59391e0);
        if (named) {
            state = setState(named->node->name210);
            Object0085dd70 *target = findNamed<Object0085dd70>(D_581d1dc, D_581d718);
            if (target)
                FUN_0085dd70(target, state, 0, named);
        }
    }
    FUN_00852180(0, event, a, b, state);
    return 1;
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the node the name at +0x14 of the second argument names,
 * when it is of the type D_5939080 points to; each of its components of the
 * type D_581ce88 points to has the count at +0xe0 raised (FUN_00857df0) or
 * lowered (FUN_00857f80); returns 1. The first argument is not read (the
 * handlers of leaf_00858390.cpp). The classes are not traced. */
struct Counted00857df0 : Component00503fb0 /* derived name */
{
    u8 unknown8c[0x54];
    int counte0; /* +0xe0 */
};

struct Object00857df0 { /* derived name */
    u8 unknown0[0x14];
    Name name14; /* +0x14 */
};

extern const Type00503fb0 *D_5939080; /* derived name: the node's type */
extern const Type00503fb0 *D_581ce88; /* derived name: the counted components' type */

// NONMATCHING: 52/113, 364 bytes against 395. Both finds' drops are in the IR (two atomicrmw, the
// loop rotated or not); the post-RA Control Flow Optimizer merges them with the tail that follows
// (one `lock dec; test; je`), where the base keeps each find's drop and found block apart
// (0x857ee2 `lock dec; jmp`, 0x857ef0 `lock dec` falling into the test). The `while` form: one copy
// of findComponent, 300 bytes (round 569D)
int FUN_00857df0(void *, const Object00857df0 *self) /* derived name */
{
    Object016b85e0 *node = findNamed<Object016b85e0>(self->name14, D_5939080);
    if (node) {
        unsigned next = 0;
        for (Component00503fb0 *component = node->findComponent(D_581ce88, next); component;
             component = node->findComponent(D_581ce88, next))
            static_cast<Counted00857df0 *>(component)->counte0++;
    }
    return 1;
}

// NONMATCHING: as FUN_00857df0
int FUN_00857f80(void *, const Object00857df0 *self) /* derived name */
{
    Object016b85e0 *node = findNamed<Object016b85e0>(self->name14, D_5939080);
    if (node) {
        unsigned next = 0;
        for (Component00503fb0 *component = node->findComponent(D_581ce88, next); component;
             component = node->findComponent(D_581ce88, next))
            static_cast<Counted00857df0 *>(component)->counte0--;
    }
    return 1;
}

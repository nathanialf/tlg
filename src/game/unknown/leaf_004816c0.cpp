/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: ends the object's active state (the flag at +0x40) once:
 * hands the records at +0x90 and +0x88 to FUN_00474c50 and FUN_004adde0,
 * passes the objects at 0x57d6b84 and 0x57d6b7c to FUN_00c63e20 with the
 * list the pointer at 0x59396d0 holds, hands the node the Name at 0x57d6b8c
 * names (of the type D_5939080 points to, usable by this thread) to
 * FUN_00c57220 when it has a parent, and empties the counted reference at
 * +0x1e8, the node it held handed to FUN_00c57220 when bit 0 of its +0x24 is
 * set. FUN_00466400 calls it (0x466416). The classes are not traced. */
struct Record004816c0; /* derived name */
struct List059396d0;   /* derived name */

/* the record at +0x900 of the record at +0x38 of the object the pointer at
 * 0x57c9390 holds (leaf_00466400.cpp passes it) */
struct Member057c9390_38_900 { /* derived name */
    u8 unknown0[0x40];
    bool active40; /* +0x40 */
    u8 unknown41[0x47];
    Record004816c0 *unknown88; /* +0x88 */
    Record004816c0 *unknown90; /* +0x90 */
    u8 unknown98[0x150];
    AtomicRef0045c470<Node00503fb0> held1e8; /* +0x1e8 */
};

extern List059396d0 *D_59396d0;
extern Name D_57d6b7c;                /* derived name */
extern Name D_57d6b84;                /* derived name */
extern Name D_57d6b8c;                /* derived name */
extern const Type00503fb0 *D_5939080; /* derived name: the node's type */

void FUN_00474c50(Record004816c0 *record);                            /* derived name */
void FUN_004adde0(Record004816c0 *record);                            /* derived name */
void FUN_00c63e20(List059396d0 *list, const Name *name, int unknown); /* derived name */
void FUN_00c57220(Node00503fb0 *node);                                /* derived name */

// NONMATCHING: 118 of 119: the first exchange's success: the build threads it past clear()'s null
// test to the count's test (`je` 5 bytes further), the base joins the loop's exit (`test rbx, rbx`
// at 0x4817f4)
void FUN_004816c0(Member057c9390_38_900 *self) /* derived name */
{
    if (!self->active40)
        return;
    self->active40 = false;
    FUN_00474c50(self->unknown90);
    FUN_004adde0(self->unknown88);
    FUN_00c63e20(D_59396d0, &D_57d6b84, 0);
    FUN_00c63e20(D_59396d0, &D_57d6b7c, 0);
    Node00503fb0 *node = findNamed<Node00503fb0>(D_57d6b8c, D_5939080);
    if (node && node->parent)
        FUN_00c57220(node);
    if (Node00503fb0 *held = self->held1e8.get()) {
        self->held1e8.clear();
        if (held->unknown24 & 1)
            FUN_00c57220(held);
    }
}

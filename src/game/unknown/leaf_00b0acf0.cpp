/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: by the reference's owner's mode at +0x2550 (1 to 5, the
 * jump table 0x1558ee8; 3 and any other mode do nothing) takes one of four
 * marks of the owner (+0x5580, +0x4ba0, +0x5e30, +0x3ad0 for 1, 2, 4, 5); when
 * the owner has its body (+0x28), the object's mark at +0x10 becomes the
 * owner's less the body's position (+0x120), its int taken from the owner's,
 * and FUN_00b0a9f0 runs on the object with that int (a tail call), as
 * FUN_00b0adf0 does with its points. What the modes and the int mean is not
 * traced. */
struct Mark00b0acf0 { /* derived name */
    float x, y, z;
    int id;
};

struct Body00b0acf0 { /* derived name */
    u8 unknown0[0x120];
    float x, y, z; /* +0x120 */
};

struct Owner00b0acf0 { /* derived name */
    u8 unknown0[0x28];
    Body00b0acf0 *body; /* +0x28 */
    u8 unknown30[0x2550 - 0x30];
    int mode; /* +0x2550 */
    u8 unknown2554[0x3ad0 - 0x2554];
    Mark00b0acf0 fifth; /* +0x3ad0 */
    u8 unknown3ae0[0x4ba0 - 0x3ae0];
    Mark00b0acf0 second; /* +0x4ba0 */
    u8 unknown4bb0[0x5580 - 0x4bb0];
    Mark00b0acf0 first; /* +0x5580 */
    u8 unknown5590[0x5e30 - 0x5590];
    Mark00b0acf0 fourth; /* +0x5e30 */
};

struct Reference00b0acf0 { /* derived name */
    Owner00b0acf0 *owner;
};

struct Object00b0acf0 { /* derived name */
    u8 unknown0[0x10];
    Mark00b0acf0 offset; /* +0x10 */
};

void FUN_00b0a9f0(Object00b0acf0 *self, const Reference00b0acf0 *reference,
                  int id); /* derived name */

// NONMATCHING: list-ilp order, as FUN_00b0adf0's: the subtractions from z down where the base
// subtracts +0x120 first (vsubss), with the cases' lea order and registers following
void FUN_00b0acf0(Object00b0acf0 *self, const Reference00b0acf0 *reference) /* derived name */
{
    const Owner00b0acf0 *owner = reference->owner;
    Mark00b0acf0 mark;
    switch (owner->mode) {
    case 1:
        mark = owner->first;
        break;
    case 2:
        mark = owner->second;
        break;
    case 4:
        mark = owner->fourth;
        break;
    case 5:
        mark = owner->fifth;
        break;
    default:
        return;
    }
    const Body00b0acf0 *body = owner->body;
    if (body) {
        Mark00b0acf0 offset = {mark.x - body->x, mark.y - body->y, mark.z - body->z, mark.id};
        self->offset = offset;
        FUN_00b0a9f0(self, reference, mark.id);
    }
}

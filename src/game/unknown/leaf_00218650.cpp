/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a callback whose address FUN_00858550 takes (lea at
 * 0x858583): when the id its second argument points to is in the object's
 * array of ids (the data at +0x38, the count at +0x40), calls FUN_002178a0
 * on the object and clears bit 2 of the flags byte at +0x34; returns 1.
 * The array's lookup gives the index or -1. The ids' meaning is not
 * traced. */
struct Object00218650 /* derived name */
{
    u8 unknown0[0x34];
    u8 unknown34; /* +0x34: flags */
    u8 unknown35[3];
    int *ids38;       /* +0x38 */
    unsigned count40; /* +0x40 */

    int indexOf(const int &id) const /* derived name */
    {
        for (int i = 0; i < count40; ++i) {
            if (id == ids38[i])
                return i;
        }
        return -1;
    }
};

void FUN_002178a0(Object00218650 *self); /* derived name */

// NONMATCHING: list-ilp's order of the two loads hoisted before the loop and the
// compare's operands: written `id == ids38[i]` the loads are the base's and the
// compare is `cmp esi, [rdx + rcx*4]` (the base `cmp [rdx + rcx*4], esi`);
// written `ids38[i] == id` (by value or by reference) the compare is the base's
// and the two loads come the other way.
int FUN_00218650(Object00218650 *self, const int *id) /* derived name */
{
    if (self->indexOf(*id) >= 0) {
        FUN_002178a0(self);
        self->unknown34 &= ~4;
    }
    return 1;
}

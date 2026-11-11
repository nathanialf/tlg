/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a slot of a vtable without a row (its pointer at 0x16b12b8):
 * unless the int at +0x5c is set, hands the time step to FUN_0092da90 for each
 * entry of the array at +0x50 (0x100 bytes each, the unsigned count at +0x58)
 * whose two low bits at +0xe4 are both set; returns 1. The entries' class and
 * the bits' meaning are not traced. */
struct Entry00968760 { /* derived name */
    u8 unknown0[0xe4];
    u32 flags; /* +0xe4 */
    u8 unknowne8[0x18];
};

struct Object00968760 { /* derived name */
    u8 unknown0[0x50];
    Entry00968760 *entries; /* +0x50 */
    u32 count;              /* +0x58 */
    int unknown5c;          /* +0x5c */
};

void FUN_0092da90(Entry00968760 *entry, float step); /* derived name */

// NONMATCHING: the two-bit test: the base masks and compares (`and edx, 3; cmp edx, 3; jne`),
// the build turns `(x & 3) == 3` into `andn edx, edx, r15d` with 3 kept in r15
// (TargetLowering::simplifySetCCWithAnd, hasAndNotCompare under BMI), one register more to save;
// the base has the and-compare form at 245 multi-bit sites of the region
int FUN_00968760(Object00968760 *self, float step) /* derived name */
{
    if (!self->unknown5c) {
        for (u32 i = 0; i < self->count; ++i) {
            Entry00968760 *entry = &self->entries[i];
            if ((entry->flags & 3) == 3)
                FUN_0092da90(entry, step);
        }
    }
    return 1;
}

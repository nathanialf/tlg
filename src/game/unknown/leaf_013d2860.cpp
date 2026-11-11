/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 109 of the vtable of Object00f0e560 (0x16bedb8,
 * config/vtables.derived.base.txt; its pointer at 0x16bf130), written as a
 * free function: in each of the 96-byte records from +0x10, as many as the
 * unsigned int at +0xd0 counts, sets the int at +0x0 to 1 and the one at
 * +0x50 to 0. */
struct Entry013d2860 /* derived name */
{
    int unknown0; /* +0x0 */
    u8 unknown4[0x4c];
    int unknown50; /* +0x50 */
    u8 unknown54[0xc];
};

struct Object013d2860 /* derived name */
{
    u8 unknown0[0x10];
    Entry013d2860 unknown10[2]; /* +0x10: its extent not traced */
    unsigned unknownD0;         /* +0xd0 */
};

// NONMATCHING: the base tests the byte extent (`shl rax, 5; lea rax, [rax + 2*rax];
// test rax, rax`) before the loop, a compare InstCombine keeps only when the
// offset's multiply has no wrap flag; an array index (here, and an index loop)
// gives the count's test.
void FUN_013d2860(Object013d2860 *self) /* derived name */
{
    for (Entry013d2860 *entry = self->unknown10, *end = self->unknown10 + self->unknownD0;
         entry != end; ++entry) {
        entry->unknown0 = 1;
        entry->unknown50 = 0;
    }
}

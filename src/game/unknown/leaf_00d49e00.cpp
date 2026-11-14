/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: copies the four 16-bit values at +0x278 of each entry of
 * the source's list into the entry of the same index of the destination's
 * (the lists of pointers at +0x238, the destination's count at +0x240 read
 * once), value by value. The first argument is not read. Class and method
 * unknown. */
struct Entry00d49e00 { /* derived name */
    u8 unknown0[0x278];
    u16 unknown278[4]; /* +0x278 */
};

struct List00d49e00 { /* derived name */
    u8 unknown0[0x238];
    Entry00d49e00 **entries238; /* +0x238 */
    int count240;               /* +0x240 */
};

struct Object00d49e00; /* derived name */

// The exit compare is the truncated induction variable (`inc rcx; cmp r8d,
// ecx`): docs/DECISIONS.md D65.
void FUN_00d49e00(Object00d49e00 *, const List00d49e00 *source,
                  List00d49e00 *target) /* derived name */
{
    int count = target->count240;
    for (int i = 0; i < count; ++i) {
        Entry00d49e00 *to = target->entries238[i];
        const Entry00d49e00 *from = source->entries238[i];
        for (int k = 0; k < 4; ++k)
            to->unknown278[k] = from->unknown278[k];
    }
}

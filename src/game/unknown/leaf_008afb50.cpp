/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"

/* derived names: returns (|x| - 0.5) * 100 for the float x at +0x40 of the
 * record at +0x100 of the object the pointer at 0x57c9390 holds (the absolute
 * value an `andps` with 0x7fffffff); slot 2 of the vtable at 0x16af690 (its
 * pointer at 0x16af6b0), stored by FUN_0088b4e0 and the destructors
 * FUN_008afad0 and FUN_008afb10. The object itself is not read. */
struct Object008afb50; /* derived name */

struct Member057c9390_100 { /* derived name */
    u8 unknown0[0x40];
    float unknown40;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x100];
    Member057c9390_100 *unknown100;
};

extern Object057c9390 *D_57c9390;

// NONMATCHING: equal instruction by instruction (quick_diff, the whole module), refused by the
// gate's layout: the fabs mask's 16-byte constant-pool entry (.LCPI, 0x7fffffff four times) occurs
// 534 times in the base, so tools/layout_link.py cannot place it (`LAYOUT ERROR ... occur 534
// times`); claimable when the layout resolves the entry from the base's own reference (0x15390a0)
float FUN_008afb50(Object008afb50 *) /* derived name */
{
    return (fabsf(D_57c9390->unknown100->unknown40) - 0.5f) * 100.0f;
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: negates the float at 0x40 of the record at +0x100 of the
 * object the pointer at 0x57c9390 holds and returns whether it was positive
 * (`ucomiss 0, x; sbb`); slot 2 of the vtable at 0x16af8c0 (its pointer at
 * 0x16af8e0), stored by FUN_0088b4e0 and the destructors FUN_008b0410 and
 * FUN_008b0460. The object itself is not read. */
struct Object008b04b0; /* derived name */

struct Member057c9390_100 { /* derived name */
    u8 unknown0[0x40];
    float unknown40;
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x100];
    Member057c9390_100 *unknown100;
};

extern Object057c9390 *D_57c9390;

// NONMATCHING: list-ilp order and greedy's assignment: the base computes the result (`sbb eax,
// eax; and eax, 1`) before the store and keeps the record in rcx, the compile stores first with
// the record in rax; the compare equal (`ucomiss 0, x`: the result computed before the store in
// the source compiles the same)
int FUN_008b04b0(Object008b04b0 *) /* derived name */
{
    Member057c9390_100 *record = D_57c9390->unknown100;
    float value = record->unknown40;
    record->unknown40 = -value;
    return value <= 0.0f ? 0 : 1;
}

/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: negates the float at 0x44 of the record at +0x100 of the
 * object the pointer at 0x57c9390 holds and returns whether it was positive
 * (`ucomiss 0, x; sbb`); slot 2 of the vtable at 0x16af820 (its pointer at
 * 0x16af840), stored by FUN_0088b4e0 and the destructors FUN_008b01c0 and
 * FUN_008b0210. The object itself is not read. */
struct Object008b0260; /* derived name */

struct Member057c9390_100 { /* derived name */
    u8 unknown0[0x44];
    float unknown44;
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
int FUN_008b0260(Object008b0260 *) /* derived name */
{
    Member057c9390_100 *record = D_57c9390->unknown100;
    float value = record->unknown44;
    record->unknown44 = -value;
    return value <= 0.0f ? 0 : 1;
}

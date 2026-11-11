/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: when the int at +0x238 of its second argument and the int at
 * +0x34 of the object are nonzero, the record the pointer at +0x4b0 of the
 * argument holds is null or has bit 0 of its byte at +0x4c clear, and the int
 * at +0xac of the object is 0, passes the object and the argument to
 * FUN_00d1e440, a tail call; slot 10 of the vtable at 0x16ba0e8 (its pointer
 * at 0x16ba148), stored by FUN_00d1dfa0 and FUN_00d1e230. The types and the
 * callee's return type are not traced. */
struct Record00d1f5a0 { /* derived name */
    u8 unknown0[0x4c];
    u8 unknown4c;
};

struct Argument00d1f5a0 { /* derived name */
    u8 unknown0[0x238];
    int unknown238;
    u8 unknown23c[0x274];
    Record00d1f5a0 *unknown4b0;
};

struct Object00d1f5a0 { /* derived name */
    u8 unknown0[0x34];
    int unknown34;
    u8 unknown38[0x74];
    int unknownac;
};

void FUN_00d1e440(Object00d1f5a0 *object, Argument00d1f5a0 *argument); /* derived name */

void FUN_00d1f5a0(Object00d1f5a0 *self, Argument00d1f5a0 *argument) /* derived name */
{
    if (argument->unknown238 == 0 || self->unknown34 == 0)
        return;
    Record00d1f5a0 *record = argument->unknown4b0;
    if (record && (record->unknown4c & 1))
        return;
    if (self->unknownac == 0)
        FUN_00d1e440(self, argument);
}

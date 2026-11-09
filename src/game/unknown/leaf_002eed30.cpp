/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears the five ints at +0x584 to +0x594 (the first four in
 * one 16-byte store); slot 48 of the vtable at 0x16a8260 (its pointer at
 * 0x16a83f0). Class and method unknown. */
struct Object002eed30 { /* derived name */
    u8 unknown0[0x584];
    int unknown584;
    int unknown588;
    int unknown58c;
    int unknown590;
    int unknown594;
};

void FUN_002eed30(Object002eed30 *self) /* derived name */
{
    self->unknown584 = 0;
    self->unknown588 = 0;
    self->unknown58c = 0;
    self->unknown590 = 0;
    self->unknown594 = 0;
}

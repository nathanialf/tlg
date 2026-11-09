/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the int at +0x19c; slot 9 of the vtable at 0x16abb00
 * (its pointer at 0x16abb58), the vtable stored by FUN_005b05b0 FUN_005b14b0;
 * slot 9 of the vtable at 0x16abc58 (its pointer at 0x16abcb0), the vtable
 * stored by FUN_005c6060 FUN_005c6620. The int is the `mov eax` width; its
 * meaning is not traced. Class and method unknown. */
struct Object0135e490 { /* derived name */
    u8 unknown0[0x19c];
    int unknown19c;
};

int FUN_0135e490(const Object0135e490 *self) /* derived name */
{
    return self->unknown19c;
}

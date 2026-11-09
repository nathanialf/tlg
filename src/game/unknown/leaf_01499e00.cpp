/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: clears the 0x400 bytes at +0x1980 with memset, as a tail
 * call; slot 20 of the vtable at 0x16c39b8 (its pointer at 0x16c3a68), the
 * vtable stored by FUN_0130c660 FUN_0130dea0. Class and method unknown. */
#include "tlg_libc.h"

struct Object01499e00 { /* derived name */
    u8 unknown0[0x1980];
    u8 unknown1980[0x400];
};

void FUN_01499e00(Object01499e00 *self) /* derived name */
{
    memset(self->unknown1980, 0, sizeof(self->unknown1980));
}

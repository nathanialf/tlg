/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: sets the int at +0x64 to 1 when bit 0 of the byte at +0x60 is
 * set (testb $1: a one-bit field, as a bool member compiles to cmpb $0); slot
 * 7 of the vtable at 0x16b7e18 (its pointer at 0x16b7e60), the vtable stored
 * by FUN_00bff9d0 FUN_013a1bf0. Class and method unknown. */
struct Object013a1bf0 { /* derived name */
    u8 unknown0[0x60];
    u8 unknown60 : 1; /* bit 0 of the byte at +0x60; its other bits not traced */
    u8 unknown61[0x64 - 0x61];
    int unknown64;
};

void FUN_00bffb00(Object013a1bf0 *self) /* derived name */
{
    if (self->unknown60)
        self->unknown64 = 1;
}

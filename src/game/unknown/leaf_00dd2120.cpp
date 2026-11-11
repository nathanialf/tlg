/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 30 of the vtables at 0x16bba90 and 0x16bc170 (and one
 * more pointer; FUN_00dd2180's vtables): FUN_013bf510 on the object with the
 * pointer at +0x8 of its argument, then FUN_013bf700 with the pointer at
 * +0x18, as a tail call. The types are not traced. Class and method unknown. */
struct Object00dd2120; /* derived name */

struct Argument00dd2120 { /* derived name */
    u8 unknown0[8];
    void *unknown8;
    u8 unknown10[8];
    void *unknown18;
};

void FUN_013bf510(Object00dd2120 *self, void *value); /* derived name */
void FUN_013bf700(Object00dd2120 *self, void *value); /* derived name */

void FUN_00dd2120(Object00dd2120 *self, const Argument00dd2120 *argument) /* derived name */
{
    FUN_013bf510(self, argument->unknown8);
    FUN_013bf700(self, argument->unknown18);
}

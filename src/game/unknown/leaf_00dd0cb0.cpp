/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013c8500.h"

/* derived names: slot 0 of the vtables at 0x16bba90 and 0x16bc170 (and one
 * more pointer): when the pointer at +0x8 is set, FUN_013bf660 with it and the
 * pointer at +0x10, then the first cleared (Object013c8500::release's
 * body). Class and method unknown. */
struct Object00dd0cb0 { /* derived name */
    u8 unknown0[8];
    VisitedNode00dd1740 *unknown8;
    HksState00dd1740 *unknown10;
};

void FUN_00dd0cb0(Object00dd0cb0 *self) /* derived name */
{
    if (self->unknown8) {
        FUN_013bf660(self->unknown8, self->unknown10);
        self->unknown8 = 0;
    }
}

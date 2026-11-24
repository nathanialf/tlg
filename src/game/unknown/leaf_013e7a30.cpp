/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_frames013fb310.h"

/* derived names: slot 3 of the vtable at 0x16d4ba0 (its pointer at
 * 0x16d4bc8) and of the vtable at 0x16d4d50 (its pointer at 0x16d4d78):
 * the poser's model kept at +0x8 and two ints at +0x9c and +0xa0, then
 * every frame set made `count` frames long (FUN_013e5560, as a tail call).
 * Class and method unknown. */
struct Object013e7a30 : FramePoser013fccf0 { /* derived name */
    int unknowna0;                           /* +0xa0 */
};

void FUN_013e7a30(Object013e7a30 *self, FadeModel013d4610 *model, int count, int a,
                  int b) /* derived name */
{
    self->model = model;
    self->unknown9c = a;
    self->unknowna0 = b;
    FUN_013e5560(self, count);
}

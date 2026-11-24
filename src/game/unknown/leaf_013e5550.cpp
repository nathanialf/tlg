/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_frames013fb310.h"

/* derived names: slot 3 of the vtable at 0x16d4cf0 (its pointer at
 * 0x16d4d18), the vtable stored by FUN_00fcc550: the poser's model kept at
 * +0x8, then every frame set made 3 frames long (FUN_013e5560, as a tail
 * call). Class and method unknown. */
void FUN_013e5550(FramePoser013fccf0 *self, FadeModel013d4610 *model) /* derived name */
{
    self->model = model;
    FUN_013e5560(self, 3);
}

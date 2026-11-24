/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_frames013fb310.h"

/* derived name: slot 3 of the vtable at 0x16d57d0 (its pointer at
 * 0x16d57f8), the class FUN_01078df0 builds into its owner at +0x1420:
 * the model kept at +0x8, then every frame set made `count` frames long
 * (FUN_013fae50, a tail call). The object is a poser: FUN_013fae50 is
 * FUN_013e5560's body over FramePoser013fccf0 (the count at +0x98, the sets
 * at +0x28), and the pointer at +0x8 is the poser's model, which the slot 4
 * of the sibling vtable at 0x16d5668 (FUN_01404660) reads as a
 * FadeModel013d4610 (its skeleton's poses at +0x40) after that vtable's
 * slot 3 (0x1404480) stores it the same way. */
void FUN_01404cc0(FramePoser013fccf0 *self, FadeModel013d4610 *model, int count) /* derived name */
{
    self->model = model;
    FUN_013fae50(self, count);
}

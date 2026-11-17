/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object014068b0.h"

/* slot 2 of Object016d5850 (tlg_game_object014068b0.h): the
 * base's slot 2, then the three vectors set as the vectors of the poses of
 * the three indices, each with w 1 (owner, model and indices read again
 * after each store) */
void Object016d5850::FUN_01408960()
{
    Object014068b0::FUN_01408960();
    Pose014068b0 &first = owner->model->poses[indices->unknown8];
    first.unknown20 = unknown70;
    first.unknown20.w = 1.0f;
    Pose014068b0 &second = owner->model->poses[indices->unknown14];
    second.unknown20 = unknown80;
    second.unknown20.w = 1.0f;
    Pose014068b0 &third = owner->model->poses[indices->unknown18];
    third.unknown20 = unknown90;
    third.unknown20.w = 1.0f;
}
